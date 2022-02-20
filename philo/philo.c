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

int arg_valid(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int check_params(int argc, char **argv)
{
    int i;

    if (argc > 6 || argc < 5)
        return (1);
    i = 1;
    while (i < argc)
    {
        if (arg_valid(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

int init_env(int argc, char **argv, t_env *env)
{
    if (check_params(argc, argv))
        return (1);
    env->nb_philo = ft_atoi(argv[1]);
    env->time_to_die = ft_atoi(argv[2]);
    env->time_to_eat = ft_atoi(argv[3]);
    env->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        env->end_condition = ft_atoi(argv[5]);
    gettimeofday(&env->start, NULL);
    env->thread_philos = malloc(env->nb_philo * sizeof(pthread_t));
    if (!env->thread_philos)
        return (1);
    pthread_mutex_init(&env->output, NULL);
}

t_philo *init_philos(env){

}

void    *fn_philo(t_philo *philo)
{
    
}

int main(int argc, char **argv)
{
    int     i;
    int     ret;
    t_env   env;
    t_philo *philo;

    if (init_env(argc, argv, &env))
        return (0);
    philo = init_philos(env);
    if(!philo)
        return (0);
    i = -1;
    while (++i < env.nb_philo)
    {
        ret = pthread_create (&env.thread_philos[i], NULL, fn_philo, &philo);
        if (ret)
            return (clean(&env, philo));
        philo = philo->next;
    }
    i = -1;
    while (++i < env.nb_philo)
      pthread_join (env.thread_philos[i], NULL);
    return (clean(&env, philo));
}