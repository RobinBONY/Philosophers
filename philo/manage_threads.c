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
        philo->alive = 0;
        philo = philo->next;
    }
}

int is_finished(t_philo *philo)
{
    int i;
    int dead;
    int nb_philo;

    i = 0;
    dead = 0;
    nb_philo = philo->vars->nb_philo;
	while (i < nb_philo)
	{
        if (!philo->alive)
            dead++;
		philo = philo->next;
		i++;
	}
    if (dead == nb_philo)
        return (1);
    return (0);
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
        if (is_finished(philo))
            break ;
        philo = philo->next;
    }
}
