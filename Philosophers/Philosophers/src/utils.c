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
	u_int64_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < sleep_time)
		usleep(500);
}

u_int64_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (write(2, "gettimeoftheday error\n", 23));
	return (time.tv_sec * (u_int64_t)1000 + time.tv_usec / 1000);
}

void	print_message(char *color, uint64_t time, int id, char *state)
{
	printf("%s %llu %d philosopher %s\n", color, time, id, state);
}