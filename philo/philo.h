/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:20:01 by rbony             #+#    #+#             */
/*   Updated: 2022/02/22 11:43:30 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

typedef struct  s_philo
{
    int     		number;
    long    		last_meal;
	int				meal_counter;
	int				death;
	pthread_mutex_t	fork;
    struct s_env    *vars;
	struct s_philo	*next;
}               t_philo;

typedef struct  s_env
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_condition;
	pthread_t		*thread_philos;
    pthread_mutex_t output;
	struct timeval	start;
}               t_env;

long	get_timestamp(struct timeval start);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo philo);
void	ft_take_fork(t_philo philo);
void	*ft_die(t_philo *philo);
void	ft_think(t_philo philo);
int		arg_valid(char *str);
int		check_params(int argc, char **argv);
int		init_env(int argc, char **argv, t_env *env);
t_philo	*init_philos(t_env *env);
int		take_forks_pair(t_philo *philo);
int		take_forks_impair(t_philo *philo);
int		is_dead(t_philo philo);
void	*fn_philo(void *arg);
int		clean(t_env *env, t_philo *philos);
int		will_die(t_philo philo);
void	*ft_sleep_until_death(t_philo *philo);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int nb, t_env *env);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
void	ft_lstclear(t_philo **lst);

#endif