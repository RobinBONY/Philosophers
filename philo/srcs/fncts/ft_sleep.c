/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/06/15 11:24:33 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, int limit)
{
	pthread_mutex_lock(&philo->is_alive);
	while (get_timestamp(philo->vars->start) < limit && philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		usleep(10);
		pthread_mutex_lock(&philo->is_alive);
	}
	pthread_mutex_unlock(&philo->is_alive);
}

void	ft_sleep(t_philo *philo)
{
	t_env	env;

	pthread_mutex_lock(&philo->is_alive);
	if (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		env = *philo->vars;
		pthread_mutex_lock(&env.output);
		printf("%ld	%d	is sleeping\n", get_timestamp(env.start), philo->number);
		pthread_mutex_unlock(&env.output);
		ft_usleep(philo, get_timestamp(env.start) + env.time_to_sleep);
	}
	else
		pthread_mutex_unlock(&philo->is_alive);
}
