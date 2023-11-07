#include "../include/philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	philo->left_fork = 
	pthread_mutex_unlock(philo->mut_write);
}

void	mut_print_message(t_philo *philo)
{
	pthread_mutex_lock(philo->mut_write);
	philo->	last_eat_time = get_current_time();
	pthread_mutex_unlock(philo->mut_write);
}

void	nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(philo->mut_eat_t);
	philo->nb_meals_had++;
	pthread_mutex_unlock(philo->mut_eat_t);
}

void	meat_time(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message(CYAN, philo->last_eat_time, philo->id, TAKE_FORKS);
	nb_meals_had(philo->nb_meals_had);
	philo->is_eating = 1;
	mut_print_message(philo->last_eat_time);
	print_message(GREEN, philo->last_eat_time, philo->id, EAT);
	pthread_mutex_unlock(philo->right_fork);


}