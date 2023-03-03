/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/03/02 20:37:19 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *client, void *ucontext)
{
	static char	c = 0;
	static int	x = 0;

	(void) ucontext;
	if (sig == SIGUSR2)
		x++;
	else if (sig == SIGUSR1)
	{
		c |= 1 << x;
		x++;
	}
	if (x == 8)
	{
		if ((int)c == 0)
			kill(client->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		c = 0;
		x = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf(GREEN BOLD "[CONNECTING]\n" RESET "PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}