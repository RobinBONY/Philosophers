/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/02/21 10:46:54 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
sec_of_day = epoch.tv_sec % (24 * 60 * 60);
hour       = sec_of_day / (60 * 60);
minute     = sec_of_day % (60 * 60) / 60;
*/

long	get_timestamp(long start)
{
	long			delta;
	struct timeval	now;

	gettimeofday(&now, NULL);
	delta = (now.tv_sec - start) * 1000;
	return (delta);
}

void	ft_eat(t_philo *philo)
{
	t_env	env;

	env = *philo->vars;
	philo->last_meal = get_timestamp(env.start.tv_sec);
	philo->meal_counter++;
	pthread_mutex_lock(&env.output);
	printf("%ld %d is eating\n", get_timestamp(env.start.tv_sec), philo->number);
	pthread_mutex_unlock(&env.output);
	usleep(env.time_to_eat * 1000);
}

void	ft_sleep(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld %d is sleeping\n", get_timestamp(env.start.tv_sec), philo.number);
	pthread_mutex_unlock(&env.output);
	usleep(env.time_to_sleep * 1000);
}

void	ft_take_fork(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld %d has taken a fork\n", get_timestamp(env.start.tv_sec),
		philo.number);
	pthread_mutex_unlock(&env.output);
}

void	*ft_die(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	
	pthread_mutex_lock(&env.output);
	printf("%ld %d died\n", get_timestamp(env.start.tv_sec), philo.number);
	printf("dead at %ld\n", philo.last_meal + env.time_to_die);
	pthread_mutex_unlock(&env.output);
	return (NULL);
}

void	ft_think(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld %d is thinking\n", get_timestamp(env.start.tv_sec), philo.number);
	pthread_mutex_unlock(&env.output);
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

int	take_forks_pair(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (is_dead(*philo))
		return (1);
	ft_take_fork(*philo);
	pthread_mutex_lock(&philo->next->fork);
	if (is_dead(*philo))
		return (1);
	ft_take_fork(*philo);
	ft_eat(philo);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}

int	take_forks_impair(t_philo *philo)
{
	pthread_mutex_lock(&philo->next->fork);
	if (is_dead(*philo))
		return (1);
	ft_take_fork(*philo);
	pthread_mutex_lock(&philo->fork);
	if (is_dead(*philo))
		return (1);
	ft_take_fork(*philo);
	ft_eat(philo);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	return (0);
}

int	is_dead(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	if (get_timestamp(env.start.tv_sec) - philo.last_meal > env.time_to_die)
		return (1);
	return (0);
}

int	will_die(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	if ((get_timestamp(env.start.tv_sec) + env.time_to_sleep)
		- philo.last_meal < env.time_to_die)
		return (1);
	return (0);
}

void	*ft_sleep_until_death(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld %d is sleeping\n", get_timestamp(env.start.tv_sec), philo.number);
	pthread_mutex_unlock(&env.output);
	usleep(((get_timestamp(env.start.tv_sec) + env.time_to_sleep)
		- philo.last_meal) * 1000);
	return (ft_die(philo));
}

void	*fn_philo(void *arg)
{
	t_env	env;
	t_philo *philo;

	philo = arg;
	env = *philo->vars;
	while (philo->meal_counter < env.end_condition)
	{
		if (is_dead(*philo))
			return(ft_die(*philo));
		if (philo->number % 2 == 0)
		{
			if (take_forks_pair(philo))
				return(ft_die(*philo));
		}
		else
		{
			if (take_forks_impair(philo))
				return(ft_die(*philo));
		}
		if (will_die(*philo))
			return (ft_sleep_until_death(*philo));
		ft_sleep(*philo);
		ft_think(*philo);
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
	i = -1;
	while (++i < env.nb_philo)
		pthread_join (env.thread_philos[i], NULL);
	return (clean(&env, philo));
}
