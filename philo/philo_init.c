/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:25:34 by rbony             #+#    #+#             */
/*   Updated: 2022/02/28 16:26:13 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_env(int argc, char **argv, t_env *env)
{
	if (check_params(argc, argv))
		return (1);
	env->nb_philo = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	env->end_condition = -1;
	if (argc == 6)
		env->end_condition = ft_atoi(argv[5]);
	gettimeofday(&env->start, NULL);
	env->thread_philos = malloc(env->nb_philo * sizeof(pthread_t));
	if (!env->thread_philos)
		return (1);
	pthread_mutex_init(&env->output, NULL);
	return (0);
}

t_philo	*init_philos(t_env *env)
{
	int		i;
	t_philo	*philos;
	t_philo	*new_node;

	i = 1;
	philos = NULL;
	while (i <= env->nb_philo)
	{
		new_node = ft_lstnew(i, env);
		if (!new_node)
		{
			ft_lstclear(&philos);
			break ;
		}
		ft_lstadd_back(&philos, new_node);
		i++;
	}
	new_node = ft_lstlast(philos);
	new_node->next = philos;
	return (philos);
}
