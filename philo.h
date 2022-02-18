/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:20:01 by rbony             #+#    #+#             */
/*   Updated: 2022/01/20 12:39:19 by rbony            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <thread.h>

typedef struct  s_philo
{
    int     		number;
    long    		last_meal;
	int				meal_counter;
	mtx
	struct s_philo	neighbour;
}               t_philo;

typedef struct  s_env
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_condition;
	struct timeval	start;
	struct timeval 	now;
}               t_env;

#endif