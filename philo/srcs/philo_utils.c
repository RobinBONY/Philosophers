/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:23:59 by rbony             #+#    #+#             */
/*   Updated: 2022/06/15 13:21:09 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_timestamp(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec - start.tv_sec) + 1e-6
			* (end.tv_usec - start.tv_usec)) * 1000);
}

int	arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_params(int argc, char **argv)
{
	int	i;

	if (argc > 6 || argc < 5)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (arg_valid(argv[i]))
			return (1);
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (1);
	return (0);
}

int	is_dead(t_philo *philo)
{
	t_env	env;

	pthread_mutex_lock(&philo->is_alive);
	if (philo->alive)
	{
		pthread_mutex_unlock(&philo->is_alive);
		env = *philo->vars;
		pthread_mutex_lock(&philo->is_eating);
		if (get_timestamp(env.start) - philo->last_meal > env.time_to_die)
		{
			pthread_mutex_unlock(&philo->is_eating);
			return (1);
		}
		pthread_mutex_unlock(&philo->is_eating);
	}
	else
		pthread_mutex_unlock(&philo->is_alive);
	return (0);
}

int	clean(t_env *env, t_philo *philos)
{
	ft_lstclear(&philos);
	pthread_mutex_destroy(&env->output);
	pthread_mutex_destroy(&env->is_afk);
	free(env->thread_philos);
	return (0);
}
