/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/03/05 01:44:49 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/philo.h"

void	ft_die(t_philo philo)
{
	t_env	env;

	env = *philo.vars;
	pthread_mutex_lock(&env.output);
	printf("%ld	%d	died\n", get_timestamp(env.start), philo.number);
	printf("dead at %ld\n", philo.last_meal + env.time_to_die);
	pthread_mutex_unlock(&env.output);
}
