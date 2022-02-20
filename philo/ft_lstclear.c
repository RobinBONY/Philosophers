/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:03:00 by rbony             #+#    #+#             */
/*   Updated: 2022/02/07 10:33:58 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstclear(t_philo **lst)
{
	t_philo	*last;

	if (!*lst)
		return ;
	while (*lst)
	{
		last = (*lst)->next;
		free(*lst);
		*lst = last;
	}
	lst = NULL;
}
