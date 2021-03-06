/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:20:01 by rbony             #+#    #+#             */
/*   Updated: 2022/06/15 10:53:51 by rbony            ###   ########lyon.fr   */
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

typedef struct s_fork
{
	pthread_mutex_t	is_available;
	int				available;
}				t_fork;

typedef struct s_philo
{
	int				number;
	long			last_meal;
	pthread_mutex_t	is_eating;
	int				meal_counter;
	int				alive;
	pthread_mutex_t	is_alive;
	struct s_fork	fork;
	struct s_env	*vars;
	struct s_philo	*next;
}				t_philo;

typedef struct s_env
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_condition;
	pthread_t		*thread_philos;
	int				afk;
	pthread_mutex_t	is_afk;
	pthread_mutex_t	output;
	struct timeval	start;
}				t_env;

int		is_afk(t_philo *philo, int end_condition);
long	get_timestamp(struct timeval start);
void	manage_threads(t_env *env, t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_take_fork(t_philo *philo);
void	ft_die(t_philo philo);
void	ft_think(t_philo *philo);
int		arg_valid(char *str);
int		check_params(int argc, char **argv);
int		init_env(int argc, char **argv, t_env *env);
t_philo	*init_philos(t_env *env);
void	take_forks_pair(t_philo *philo);
void	take_forks_impair(t_philo *philo);
int		is_dead(t_philo *philo);
void	*fn_philo(void *arg);
int		clean(t_env *env, t_philo *philos);
int		will_die(t_philo philo);
void	*ft_sleep_until_death(t_philo *philo);
void	go_afk(t_philo *philo);
void	kill_philos(t_philo *philo);

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int nb, t_env *env);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **alst, t_philo *newlst);
void	ft_lstclear(t_philo **lst);
void	ft_usleep(t_philo *philo, int limit);

#endif