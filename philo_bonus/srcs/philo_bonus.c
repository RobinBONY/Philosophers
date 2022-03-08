/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/03/08 19:36:28 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	execute_philo(t_philo *philo)
{
	int	ret;
	
	ret = pthread_create(&philo->life, NULL, fn_philo, philo);
	if (ret)
		exit(0);
	manage_thread(philo);
}

void	manage_processes(t_env *env, t_philo *philo)
{
	int i;
	int	status;
	
	i = 0;
	status = 0;
	while (i < env->nb_philo)
	{
		waitpid(-1, &status, 0);
		if (status)
		{
			kill_philos(philo);
			ft_die(env, status);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_env	env;
	t_philo	*philo;

	if (init_env(argc, argv, &env))
		return (0);
	philo = init_philos(&env);
	if (!philo)
		return (0);
	i = 0;
	while (i < env.nb_philo)
	{
		philo->pid = fork();
		if (philo->pid < 0)
			return (clean(&env, philo));
		if (philo->pid == 0)
			execute_philo(philo);
		philo = philo->next;
	}
	manage_processes(&env, philo);
	return (clean(&env, philo));
}
