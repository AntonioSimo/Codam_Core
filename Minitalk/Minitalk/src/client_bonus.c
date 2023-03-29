/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 13:11:17 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/29 15:07:51 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_message(pid_t pid, char *str)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		x = 0;
		while (x < 8)
		{
			if ((str[i] >> x) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(160);
			x++;
		}
		i++;
	}
}

void	message_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf(GREEN BOLD "Message sent\n" RESET);
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	action;

	if (argc < 3)
	{	
		ft_printf(RED BOLD "Too few arguments. You should send the program name, the correct PID and the message you want to send in quotes.\n" RESET);
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		ft_printf(RED BOLD "You should use quotes if you want to send a sentence with more than one word.\n" RESET);
		exit(EXIT_FAILURE);
	}
	action.sa_handler = message_handler;
	signal(SIGUSR1, message_handler);
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
	return (0);
}