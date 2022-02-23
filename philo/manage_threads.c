/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/02/22 11:43:57 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    kill_philos(t_philo *philo)
{
    while (philo->alive)
    {
        philo->alive--;
        philo = philo->next;
    }
}

void    manage_threads(t_env env, t_philo *philo)
{
    while (philo)
    {
        if (is_dead(*philo))
        {
            ft_die(*philo);
            kill_philos(philo);
            break;
        }
        if (env.end_condition != -1)
        {
            if (philo->meal_counter >= env.end_condition)
                philo->alive--;
        }
        philo = philo->next;
    }
}
