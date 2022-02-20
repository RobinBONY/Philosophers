/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:41:44 by rbony             #+#    #+#             */
/*   Updated: 2022/02/07 10:58:23 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int x, int y, int z)
{
	t_philo	*newlst;

	newlst = malloc(sizeof(t_philo));
	if (!newlst)
		return (NULL);
	return (newlst);
}
