/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 19:23:33 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    manage_thread(t_philo *philo)
{
    while (philo)
    {
        if (is_dead(philo))
            exit(philo->number);
    }
}
