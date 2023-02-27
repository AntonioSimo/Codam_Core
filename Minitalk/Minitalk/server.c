/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/27 17:25:59 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define GREEN "\033[32;1m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

void	signal_handler(int sig, siginfo_t *client, void *ucontext)
{
	static char	c;
	static int	x;

	c <<= 1;
	if (sig == SIGUSR1)
		c += 1;
	else if (sig == SIGUSR2)
		c += 0;
	x++;
	if (x == 8)
	{
		write(1, &c, 1);
		if (!c)
			kill(client->si_pid, SIGUSR2);
		x = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_NODEFER | SA_RESTART;
	sigemptyset(&(sa.sa_mask));
	pid = getpid();
	printf(GREEN BOLD "[CONNECTING]\n" RESET "PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
