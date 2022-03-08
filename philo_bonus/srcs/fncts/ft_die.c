/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:22:43 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 19:42:26 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_die(t_env *env, int number)
{
	sem_wait(env->output);
	printf("%ld	%d	died\n", get_timestamp(env->start), number);
	sem_post(env->output);
}
