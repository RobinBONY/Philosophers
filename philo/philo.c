/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 06:33:41 by rbony             #+#    #+#             */
/*   Updated: 2022/02/28 16:26:03 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks_pair(t_philo *philo)
{
	if (philo->alive)
	{
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(*philo);
		pthread_mutex_lock(&philo->next->fork);
		ft_take_fork(*philo);
		ft_eat(philo);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
	}
}

void	take_forks_impair(t_philo *philo)
{
	if (philo->alive)
	{
		pthread_mutex_lock(&philo->next->fork);
		ft_take_fork(*philo);
		pthread_mutex_lock(&philo->fork);
		ft_take_fork(*philo);
		ft_eat(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
	}
}

void	*fn_philo(void *arg)
{
	t_env	env;
	t_philo	*philo;

	philo = arg;
	env = *philo->vars;
	while (philo->alive)
	{
		if (env.end_condition != -1)
		{
			if (philo->meal_counter == env.end_condition)
				philo->alive = 0;
		}
		if (philo->number % 2 == 1)
			take_forks_impair(philo);
		else
			take_forks_pair(philo);
		ft_sleep(*philo);
		ft_think(*philo);
	}
	return (NULL);
}

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
	manage_threads(env, philo);
	i = -1;
	while (++i < env.nb_philo)
		pthread_join (env.thread_philos[i], NULL);
	return (clean(&env, philo));
}
