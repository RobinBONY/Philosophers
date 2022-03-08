/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 20:07:12 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    kill_philos(t_philo *philo)
{
    int	i;
    int	nb_philo;

	i = 0;
	nb_philo = philo->vars->nb_philo;
	while (i < nb_philo)
	{
		kill(philo->pid, SIGUSR1);
		i++;
	}
}
