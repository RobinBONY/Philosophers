/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 01:34:52 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	t_env	env;
	t_philo	*philo;

	if (init_env(argc, argv, &env))
		return (0);
	philo = init_philos(&env);
	if (!philo)
		return (0);
	i = -1;
	while (++i < env.nb_philo)
	{
		ret = pthread_create(&env.thread_philos[i], NULL, fn_philo, philo);
		if (ret)
			return (clean(&env, philo));
		philo = philo->next;
	}
	manage_threads(&env, philo);
	i = -1;
	while (++i < env.nb_philo)
		pthread_join (env.thread_philos[i], NULL);
	return (clean(&env, philo));
}
