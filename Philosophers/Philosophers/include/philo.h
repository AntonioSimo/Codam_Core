/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:35:06 by asimone           #+#    #+#             */
/*   Updated: 2023/11/14 19:41:55 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define CYAN "\e[0;36m"
# define GREEN "\033[0;32m"
# define PURPLE "\e[0;35m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define RESET  "\x1b[0m"

# define EXIT 1
# define SUCCESS 0
# define ERROR "Philo error"
# define GET_TIME_ERROR "Get time of the day error"
# define MALLOC_ERROR "Malloc error"
# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	// FULL = 4, ??
	// ALIVE = 5 ??
}	t_philo_state;

typedef struct s_philo
{
	int				id;
	int				is_eating;
	int				*nb_meals;
	int				nb_meals_had;
	int				*death;
	long long		last_eat_time;
	t_philo_state	state;
	struct s_data	*data;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*mut_die_t;
	pthread_mutex_t	*mut_eat_t;
	pthread_mutex_t	*mut_write;
}	t_philo;

typedef struct s_data
{
	int				nb_meals;
	int				num_of_philos;
	int				death_check;
	long long		time_to_print;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_write;
	pthread_t		death_monitor;
	pthread_t		philos_thread;
	t_philo			*philos;
}	t_data;

//parse
int			check_input(int argc, char **argv);
int			ft_is_digit(int argc, char **argv);
int			valid_input(int argc, char **argv);

//init
int			init_data(t_data *data, int argc, char **argv);
int			init_mutexes(t_data *data);
int			init_philos(t_data *data);
int			malloc_philos(t_data *data);
int			philosophers(int argc, char **argv, t_data	*data);

//death_monitor
void		*death_monitor(void *args);
int			death_check(t_philo *philo, t_data *data);

//die_time
void		die_time(t_philo *philo, t_data *data);

//meal_time
void		leave_forks(t_philo *philo);
void		meal_time(t_philo *philo, t_data *data);
void		take_left_fork(t_philo *philo, t_data *data);
void		take_right_fork(t_philo *philo, t_data *data);

//rest_time
void		rest_time(t_philo *philo, t_data *data);

//routine
void		*routine(void *args);
int			philo_thread(t_data *data);
void		destroy_mutex(t_data *data);

//think_time
void		think_time(t_philo *philo, t_data *data);

//utils
int			ft_atoi(char *str);
long long	get_current_time(long long start_time);
void		ft_usleep(long long sleep_time);
void		print_message(t_data *data, char *color, int id, char *state);

#endif