/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:41:44 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 01:33:47 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int nb, t_env *env)
{
	t_philo	*newlst;

	newlst = malloc(sizeof(t_philo));
	if (!newlst)
		return (NULL);
	newlst->number = nb;
	newlst->last_meal = get_timestamp(env->start);
	newlst->meal_counter = 0;
	newlst->vars = env;
	newlst->next = NULL;
	newlst->alive = 1;
	pthread_mutex_init(&newlst->fork, NULL);
	pthread_mutex_init(&newlst->is_alive, NULL);
	pthread_mutex_init(&newlst->is_eating, NULL);
	return (newlst);
}
