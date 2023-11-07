#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define CYAN "\e[0;36m"
# define GREEN "\x1b[32;01m"
# define PURPLE "\e[0;35m"
# define RED "\x1b[31;01m"
# define YELLOW "\033[33;1m"
# define RESET  "\x1b[0m"

# define ERR 1
# define OK 0
# define ERROR "Philo Error\n"
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
	FULL = 4,
	ALIVE = 5
}	t_philo_state;

typedef struct s_philo
{
	int				id;
	int				is_eating;
	int				nb_meals_had;
	int				*death;
	u_int64_t		last_eat_time;
	t_philo_state	state;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*mut_die_t;
	pthread_mutex_t	*mut_eat_t;
	pthread_mutex_t	*mut_write;
	//pthread_mutex_t	mutex_last_meals; //?
	//pthread_mutex_t	mutex_nb_meals; //?
}	t_philo;

typedef struct s_data
{
	int				nb_meals;
	int				num_of_philos;
	int				death_check;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mut_die_t;
	pthread_mutex_t	mut_eat_t;
	//pthread_mutex_t	mut_sleep_t; // ?
	//pthread_mutex_t	mut_start_time; // ?
	pthread_t		monitor;
	pthread_t		philos_thread;
	t_philo			*philos;
}	t_data;

//parse
int			check_input(int argc, char **argv);
int			ft_is_digit(int argc, char **argv);
int			valid_input(int argc, char **argv);

//init
int			init_data(t_data *data, int argc, char **argv);
void		init_mutexes(t_data *data);
void		init_philos(t_data *data);
int			philosophers(int argc, char **argv, t_data *data);
int			malloc_philos(t_data *data);

//meal_time
void		mut_print_message(t_philo *philo);
void		nb_meals_had(t_philo *philo);
void		meat_time(t_philo *philo);

//rest_time
void		rest_time(t_data *data);

//think_time
void		think_time(t_data *data);

//utils
int			ft_atoi(char *str);
u_int64_t	get_current_time(void);
void		ft_usleep(uint64_t sleep_time);
void		print_message(char * color, uint64_t time, int id, char *state);

#endif