/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:35 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/26 20:56:05 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	send_message(pid_t pid, char *str)
{
	int	i;
	int	x;

	i = 0;
	while (str[i] != '\0')
	{
		x = 0;
		while (x < 8)
		{
			if (str[i] & 0x80 >> x)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(120);
			x++;
		}
		i++;
	}
}

void	message_handler(int sig)
{
	
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = atoi(argv[1]);
	if (argc != 3)
	{
		printf("No mate, You are doing something wrong");
		exit(EXIT_FAILURE);
	}
	else
		send_message(pid, argv[2]);
	return (0);
}
