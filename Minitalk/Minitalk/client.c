/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:35 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/27 17:53:41 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define GREEN "\033[32;1m"
#define RED "\033[31;1m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

void	send_message(pid_t pid, char *str)
{
	int	i;
	int	x;
	int len;

	i = 0;
	len = strlen(str);
	while (i <= len)
	{
		x = 0;
		while (x < 8)
		{
			if (str[i] & 0x80 >> x)
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
	if (sig == SIGUSR2)
	{
		printf(GREEN BOLD "Message sent\n" RESET);
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	action;

	action.sa_handler = message_handler;
	sigemptyset(&(action.sa_mask));
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = atoi(argv[1]);
	if (argc < 3)
	{	
		printf(RED BOLD "Too few arguments. You should send the program name, the correct PID and the message you want to send in quotes.\n" RESET);
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		printf(RED BOLD "You should use quotes if you want to send a sentence with more than one word.\n" RESET);
		exit(EXIT_FAILURE);
	}
	send_message(pid, argv[2]);
	return (0);
}
