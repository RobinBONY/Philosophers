/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:23:54 by rbony             #+#    #+#             */
/*   Updated: 2022/06/13 11:24:24 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_afk(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_alive);
	philo->alive = 0;
	pthread_mutex_unlock(&philo->is_alive);
	pthread_mutex_lock(&philo->vars->is_afk);
	philo->vars->afk++;
	pthread_mutex_unlock(&philo->vars->is_afk);
}

int	is_afk(t_philo *philo, int end_condition)
{
	pthread_mutex_lock(&philo->is_eating);
	if (philo->meal_counter == end_condition)
	{
		pthread_mutex_unlock(&philo->is_eating);
		return (1);
	}
	pthread_mutex_unlock(&philo->is_eating);
	return (0);
}
