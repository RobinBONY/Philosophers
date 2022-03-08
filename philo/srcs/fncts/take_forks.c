/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 01:34:47 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks_pair(t_philo *philo)
{
	if (philo->alive)
	{
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(philo);
		pthread_mutex_lock(&philo->next->fork);
		ft_take_fork(philo);
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
		ft_take_fork(philo);
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(philo);
		ft_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}
