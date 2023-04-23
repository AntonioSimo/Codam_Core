/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 14:55:52 by asimone       #+#    #+#                 */
/*   Updated: 2023/04/23 16:54:39 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_variable = 0;

void	message_handler(int sig)
{
	if (sig == SIGUSR1)
		g_variable = 1;
}

void	send_message(pid_t pid, char *str)
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
			if (str[i] & (1 << x))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			x--;
			while (1)
			{
				if (g_variable == 1)
					break;
			}
			g_variable = 0;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int i;

	i = 0;
	signal(SIGUSR1, message_handler);
	if (argc == 3)
	{	
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
	{
		ft_printf(RED BOLD "Too few arguments. You should send the program name, the correct PID and the message you want to send in quotes.\n" RESET);
		exit(EXIT_FAILURE);
	}
	return (0);
}
