/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/07 15:43:44 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
/**
* @brief	Signal handler function used for processing signals received by 
*			a process.
* @param	sig The signal number that triggered the handler.
* @param	client A pointer to a structure containing additional information 
*			about the signal and the process that sent it.
* @param	ucontext A pointer to a structure representing the process's 
*			user context.
*/
void	signal_handler(int sig, siginfo_t *client, void *ucontext)
{
	static char	c = 0;
	static int	bit = 0;

	(void)ucontext;
	c = c << 1 | (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			kill(client->si_pid, SIGUSR2);
		c = 0;
		bit = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	pid = getpid();
	sigemptyset(&sa.sa_mask);
	ft_printf(GREEN BOLD "[CONNECTING]\n" RESET "PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
