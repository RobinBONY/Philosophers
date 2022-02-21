/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:00 by rbony             #+#    #+#             */
/*   Updated: 2022/02/21 10:46:01 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstclear(t_philo **lst)
{
	int		i;
	int		nb_philo;
	t_philo	*last;

	i = 0;
	if (!*lst)
		return ;
	nb_philo = (*lst)->vars->nb_philo;
	while (i < nb_philo)
	{
		last = (*lst)->next;
		pthread_mutex_destroy(&(*lst)->fork);
		free(*lst);
		*lst = last;
		i++;
	}
	lst = NULL;
}
