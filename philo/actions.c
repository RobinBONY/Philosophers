/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/02/28 16:23:35 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	t_env	env;

	if (philo->alive)
	{
		env = *philo->vars;
		philo->last_meal = get_timestamp(env.start);
		philo->meal_counter++;
		pthread_mutex_lock(&env.output);
		printf("%ld	%d	is eating\n", get_timestamp(env.start), philo->number);
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
		printf("%ld	%d	is sleeping\n", get_timestamp(env.start), philo.number);
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
		printf("%ld	%d	has taken a fork\n", get_timestamp(env.start),
			philo.number);
		pthread_mutex_unlock(&env.output);
	}
}

void	ft_die(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld	%d	died\n", get_timestamp(env.start), philo.number);
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
		printf("%ld	%d	is thinking\n", get_timestamp(env.start), philo.number);
		pthread_mutex_unlock(&env.output);
	}
}
