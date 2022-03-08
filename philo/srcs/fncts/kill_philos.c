/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 01:34:18 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    kill_philos(t_philo *philo)
{
    pthread_mutex_lock(&philo->is_alive);
    while (philo->alive)
    {
        pthread_mutex_unlock(&philo->is_alive);
        pthread_mutex_lock(&philo->is_alive);
        philo->alive = 0;
        pthread_mutex_unlock(&philo->is_alive);
        philo = philo->next;
        pthread_mutex_lock(&philo->is_alive);
    }
    pthread_mutex_unlock(&philo->is_alive);
}
