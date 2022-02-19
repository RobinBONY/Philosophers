#include "philo.h"

/*
sec_of_day = epoch.tv_sec % (24 * 60 * 60);
hour       = sec_of_day / (60 * 60);
minute     = sec_of_day % (60 * 60) / 60;
*/

long    get_timestamp(long start)
{
    long            delta;
    struct timeval  now;

    gettimeofday(&now, NULL);
    delta = (now.tv_sec - start) * 1000;
	return (delta);
}

void    ft_eat(t_philo philo)
{
    t_env   env;

    env = *philo.vars;
    pthread_mutex_lock(&env.output);
    printf("%d %d is eating\n", get_timestamp(env.start.tv_sec), philo.number);
    pthread_mutex_unlock(&env.output);
    usleep(env.time_to_eat * 1000);
}

void    ft_sleep(t_philo philo)
{
    t_env   env;

    env = *philo.vars;
    pthread_mutex_lock(&env.output);
    printf("%d %d is sleeping\n", get_timestamp(env.start.tv_sec), philo.number);
    pthread_mutex_unlock(&env.output);
    usleep(env.time_to_sleep * 1000);
}

void	ft_take_fork(t_philo philo)
{
    t_env   env;

    env = *philo.vars;
    pthread_mutex_lock(&env.output);
	printf("%d %d has taken a fork\n", get_timestamp(env.start.tv_sec), philo.number);
    pthread_mutex_unlock(&env.output);
}

void	ft_die(t_philo philo)
{
    t_env   env;

    env = *philo.vars;
    pthread_mutex_lock(&env.output);
	printf("%d %d died\n", get_timestamp(env.start.tv_sec), philo.number);
    pthread_mutex_unlock(&env.output);
}

void	ft_think(t_philo philo)
{
    t_env   env;

    env = *philo.vars;
    pthread_mutex_lock(&env.output);
	printf("%d %d is thinking\n", get_timestamp(env.start.tv_sec), philo.number);
    pthread_mutex_unlock(&env.output);
}

int main(int ac, char **av)
{
    t_env env;

    gettimeofday(&env.start, NULL);
}