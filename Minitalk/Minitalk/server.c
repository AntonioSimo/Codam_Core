/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/24 18:56:21 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	signal_handler(int sig)
{
	static char	c;
	static int	x;

	c <<= 1;
	if (sig == SIGUSR1)
		c += 1;
	else if (sig == SIGUSR2)
		c += 0;
	x++;
	if (x==8)
	{
		write(1, &c, 1);
		x = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
