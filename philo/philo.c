/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/02/22 11:43:57 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
sec_of_day = epoch.tv_sec % (24 * 60 * 60);
hour       = sec_of_day / (60 * 60);
minute     = sec_of_day % (60 * 60) / 60;
*/

long	get_timestamp(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec - start.tv_sec) + 1e-6
            * (end.tv_usec - start.tv_usec)) * 1000);
}

void	ft_eat(t_philo *philo)
{
	t_env	env;

	if (philo->alive)
	{
		env = *philo->vars;
		philo->last_meal = get_timestamp(env.start);
		philo->meal_counter++;
		pthread_mutex_lock(&env.output);
		printf("%ld %d is eating\n", get_timestamp(env.start), philo->number);
		pthread_mutex_unlock(&env.output);
		usleep(env.time_to_eat * 1000);
	}
}

void	ft_sleep(t_philo philo)
{
	t_env	env;

	if (philo.alive)
	{
		env = *philo.vars;
		pthread_mutex_lock(&env.output);
		printf("%ld %d is sleeping\n", get_timestamp(env.start), philo.number);
		pthread_mutex_unlock(&env.output);
		usleep(env.time_to_sleep * 1000);
	}
}

void	ft_take_fork(t_philo philo)
{
	t_env	env;

	if (philo.alive)
	{
		env = *philo.vars;
		pthread_mutex_lock(&env.output);
		printf("%ld %d has taken a fork\n", get_timestamp(env.start),
			philo.number);
		pthread_mutex_unlock(&env.output);
	}
}

void	ft_die(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
		
	pthread_mutex_lock(&env.output);
	printf("%ld %d died\n", get_timestamp(env.start), philo.number);
	printf("dead at %ld\n", philo.last_meal + env.time_to_die);
	pthread_mutex_unlock(&env.output);
}

void	ft_think(t_philo philo)
{
	t_env	env;

	if (philo.alive)
	{
		env = *philo.vars;
		pthread_mutex_lock(&env.output);
		printf("%ld %d is thinking\n", get_timestamp(env.start), philo.number);
		pthread_mutex_unlock(&env.output);
	}
}

int	arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_params(int argc, char **argv)
{
	int	i;

	if (argc > 6 || argc < 5)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (arg_valid(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	init_env(int argc, char **argv, t_env *env)
{
	if (check_params(argc, argv))
		return (1);
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->end_condition = -1;
	if (argc == 6)
		env->end_condition = ft_atoi(argv[5]);
	gettimeofday(&env->start, NULL);
	env->thread_philos = malloc(env->nb_philo * sizeof(pthread_t));
	if (!env->thread_philos)
		return (1);
	pthread_mutex_init(&env->output, NULL);
	return (0);
}

t_philo	*init_philos(t_env *env)
{
	int		i;
	t_philo	*philos;
	t_philo *new_node;

	i = 1;
	philos = NULL;
	while (i <= env->nb_philo)
	{
		new_node = ft_lstnew(i, env);
		if (!new_node)
		{
			ft_lstclear(&philos);
			break ;
		}
		ft_lstadd_back(&philos, new_node);
		i++;
	}
	new_node = ft_lstlast(philos);
	new_node->next = philos;
	return (philos);
}

void	take_forks_pair(t_philo *philo)
{
	if (philo->alive)
	{
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(*philo);
		pthread_mutex_lock(&philo->next->fork);
		ft_take_fork(*philo);
		ft_eat(philo);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	take_forks_impair(t_philo *philo)
{
	if (philo->alive)
	{
		pthread_mutex_lock(&philo->next->fork);
		ft_take_fork(*philo);
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(*philo);
		ft_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

int	is_dead(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	if (get_timestamp(env.start) - philo.last_meal >= env.time_to_die)
		return (1);
	return (0);
}

void	*fn_philo(void *arg)
{
	t_env	env;
	t_philo *philo;

	philo = arg;
	env = *philo->vars;
	while (philo->alive)
	{
		if (philo->number % 2 == 0)
			take_forks_pair(philo);
		else
			take_forks_impair(philo);
		ft_sleep(*philo);
		ft_think(*philo);
		if (env.end_condition != -1)
        {
            if (philo->meal_counter == env.end_condition)
                philo->alive = 0;
        }
	}
	return (NULL);
}

int	clean(t_env *env, t_philo *philos)
{
	ft_lstclear(&philos);
	pthread_mutex_destroy(&env->output);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_env	env;
	t_philo	*philo;

	if (init_env(argc, argv, &env))
		return (0);
	philo = init_philos(&env);
	if (!philo)
		return (0);
	i = -1;
	while (++i < env.nb_philo)
	{
		ret = pthread_create(&env.thread_philos[i], NULL, fn_philo, philo);
		if (ret)
			return (clean(&env, philo));
		philo = philo->next;
	}
	manage_threads(env, philo);
	i = -1;
	while (++i < env.nb_philo)
		pthread_join (env.thread_philos[i], NULL);
	return (clean(&env, philo));
}
