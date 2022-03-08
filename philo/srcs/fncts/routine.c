/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 20:22:51 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*fn_philo(void *arg)
{
	t_env	env;
	t_philo	*philo;

	philo = arg;
	env = *philo->vars;
	pthread_mutex_lock(&philo->is_alive);
	while (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		if (env.end_condition != -1)
		{
			if (is_afk(philo, env.end_condition))
				go_afk(philo);
		}
		if (philo->number % 2 == 1)
			take_forks_impair(philo);
		else
			take_forks_pair(philo);
		ft_sleep(philo);
		ft_think(philo);
		pthread_mutex_lock(&philo->is_alive);
	}
	pthread_mutex_unlock(&philo->is_alive);
	return (NULL);
}
