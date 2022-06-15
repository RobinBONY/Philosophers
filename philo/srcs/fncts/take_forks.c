/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/06/15 10:57:21 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork.is_available);
	philo->fork.available = 1;
	pthread_mutex_unlock(&philo->fork.is_available);
}

static void	pick_fork(t_philo *philo)
{
	int	taken;

	taken = 1;
	pthread_mutex_lock(&philo->is_alive);
	while (taken && philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		pthread_mutex_lock(&philo->fork.is_available);
		if (philo->fork.available)
		{
			philo->fork.available = 0;
			taken = 0;
		}
		pthread_mutex_unlock(&philo->fork.is_available);
		pthread_mutex_lock(&philo->is_alive);
	}
	pthread_mutex_unlock(&philo->is_alive);
}

void	take_forks_pair(t_philo *philo)
{
	if (philo->alive)
	{
		pick_fork(philo);
		ft_take_fork(philo);
		pick_fork(philo->next);
		ft_take_fork(philo);
		ft_eat(philo);
		drop_fork(philo->next);
		drop_fork(philo);
	}
}

void	take_forks_impair(t_philo *philo)
{
	if (philo->alive)
	{
		pick_fork(philo->next);
		ft_take_fork(philo);
		pick_fork(philo);
		ft_take_fork(philo);
		ft_eat(philo);
		drop_fork(philo);
		drop_fork(philo->next);
	}
}
