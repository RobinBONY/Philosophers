/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:41:44 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 20:03:32 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_lstnew(int nb, t_env *env)
{
	t_philo	*newlst;

	newlst = malloc(sizeof(t_philo));
	if (!newlst)
		return (NULL);
	newlst->number = nb;
	newlst->sem_name = malloc(sizeof(char) * 2);
	if (!newlst->sem_name)
		return (NULL);
	newlst->sem_name[0] = newlst->number + 48;
	newlst->sem_name[1] = '\0';
	newlst->last_meal = get_timestamp(env->start);
	newlst->meal_counter = 0;
	newlst->vars = env;
	newlst->next = NULL;
	newlst->alive = 1;
	newlst->fork = sem_open(newlst->sem_name, O_CREAT | O_EXCL, 0644);
	sem_unlink(newlst->sem_name);
	pthread_mutex_init(&newlst->is_alive, NULL);
	pthread_mutex_init(&newlst->is_eating, NULL);
	return (newlst);
}
