/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 20:04:21 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_think(t_philo *philo)
{
	t_env	env;

	pthread_mutex_lock(&philo->is_alive);
	if (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		env = *philo->vars;
		sem_wait(env.output);
		printf("%ld	%d	is thinking\n", get_timestamp(env.start), philo->number);
		sem_post(env.output);
	}
	else
		pthread_mutex_unlock(&philo->is_alive);
}
