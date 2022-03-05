/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/03/05 01:44:39 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	ft_take_fork(t_philo *philo)
{
	t_env	env;

	pthread_mutex_lock(&philo->is_alive);
	if (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		env = *philo->vars;
		pthread_mutex_lock(&env.output);
		printf("%ld	%d	has taken a fork\n", get_timestamp(env.start),
			philo->number);
		pthread_mutex_unlock(&env.output);
	}
	else
		pthread_mutex_unlock(&philo->is_alive);
}
