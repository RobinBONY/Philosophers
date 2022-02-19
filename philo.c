#include "philo.h"

/*
sec_of_day = epoch.tv_sec % (24 * 60 * 60);
hour       = sec_of_day / (60 * 60);
minute     = sec_of_day % (60 * 60) / 60;
*/

long    get_timestamp(t_env env)
{
    long    delta;

    gettimeofday(&env.now, NULL);
    delta = (env.now.tv_sec - env.start.tv_sec) * 1000;
	return (delta);
}

void    ft_eat(int philo, t_env env)
{
    printf("%d is eating\n", philo, get_timestamp(env));
    usleep(env.time_to_eat * 1000);
}

void    ft_sleep(int philo, t_env env)
{
    printf("%d is sleeping\n", philo, get_timestamp(env));
    usleep(env.time_to_sleep * 1000);
}

void	ft_take_fork(int philo, t_env env)
{
	printf("%d has taken a fork\n", philo, get_timestamp(env));
}

void	ft_die(int philo, t_env env)
{
	printf("%d died\n", philo, get_timestamp(env));
}

void	ft_think(int philo, t_env env)
{
	printf("%d is thinking\n", philo, get_timestamp(env));
}

int main(int ac, char **av)
{
    t_env env;

    gettimeofday(&env.start, NULL);
}