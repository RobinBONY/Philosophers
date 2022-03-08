/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 01:33:12 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	t_env	env;

	pthread_mutex_lock(&philo->is_alive);
	if (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		env = *philo->vars;
		philo->last_meal = get_timestamp(env.start);
		philo->meal_counter++;
		pthread_mutex_lock(&env.output);
		printf("%ld	%d	is eating\n", get_timestamp(env.start), philo->number);
		pthread_mutex_unlock(&env.output);
		usleep(env.time_to_eat * 1000);
	}
	else
		pthread_mutex_unlock(&philo->is_alive);
}
