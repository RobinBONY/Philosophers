/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 20:08:17 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks_pair(t_philo *philo)
{
	if (philo->alive)
	{
		sem_wait(philo->fork);
		ft_take_fork(philo);
		sem_wait(philo->next->fork);
		ft_take_fork(philo);
		ft_eat(philo);
		sem_post(philo->next->fork);
		sem_post(philo->fork);
	}
}

void	take_forks_impair(t_philo *philo)
{
	if (philo->alive)
	{
		sem_wait(philo->next->fork);
		ft_take_fork(philo);
		sem_wait(philo->fork);
		ft_take_fork(philo);
		ft_eat(philo);
		sem_post(philo->fork);
		sem_post(philo->next->fork);
	}
}
