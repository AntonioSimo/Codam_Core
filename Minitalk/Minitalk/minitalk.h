/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/02/27 17:25:59 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

void	message_handler(int sig);
void	send_message(pid_t pid, char *str);
void	signal_handler(int sig, siginfo_t *client, void *ucontext);

#endif
