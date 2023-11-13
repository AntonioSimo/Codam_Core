#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	result = 0;
	neg = 1;
	while (str[i] >= 9 && str[i] <= 13 || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (neg < 0)
		return (result * neg);
	return (result);
}

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start_time;

	start_time = get_current_time(0);
	while ((get_current_time(0) - start_time) < sleep_time)
		usleep(50);
}

u_int64_t	get_current_time(u_int64_t start_time)
{
	struct timeval	time;
	u_int64_t		current_time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, "gettimeoftheday error\n", 23));
	current_time = time.tv_sec * (u_int64_t)1000 + time.tv_usec / 1000;
	return (current_time - start_time);
}

void	print_message(t_data *data, char *color, int id, char *state)
{
	pthread_mutex_lock(&data->mut_write);
	data->time_to_print = get_current_time(data->start_time);
	printf("%s %llu %d philosopher %s\n", color, data->time_to_print, id, state);
	pthread_mutex_unlock(&data->mut_write);
}
