/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 14:55:52 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/07 15:42:58 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_variable = 0;

void	message_handler(int sig)
{
	if (sig == SIGUSR1)
		g_variable = 1;
}

int	send_bit(pid_t pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1))
			return (0);
	}
	else
	{
		if (kill(pid, SIGUSR2))
			return (0);
	}
	return (1);
}

int	send_message(pid_t pid, char *str)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		x = 7;
		while (x >= 0)
		{
			if (!send_bit(pid, str[i] & (1 << x)))
				return (0);
			x--;
			while (1)
			{
				if (g_variable == 1)
					break ;
			}
			g_variable = 0;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, message_handler);
	if (argc == 3)
	{	
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			ft_printf(RED BOLD "Invalid [PID]\n");
		else if (!send_message(pid, argv[2]))
			ft_printf(RED BOLD "Fail sending message.\n" RESET);
	}
	else
	{
		ft_printf(RED BOLD "Too few arguments.\n" RESET);
		exit(EXIT_FAILURE);
	}
	return (0);
}
