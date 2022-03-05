/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/05 02:15:50 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void    manage_threads(t_env *env, t_philo *philo)
{
    while (philo)
    {
        if (is_dead(philo))
        {
            kill_philos(philo);
            usleep(1000);
            ft_die(*philo);
            break;
        }
        pthread_mutex_lock(&env->is_afk);
        if (env->afk == env->nb_philo)
        {
            pthread_mutex_unlock(&env->is_afk);
            break ;
        }
        pthread_mutex_unlock(&env->is_afk);
        philo = philo->next;
    }
}
