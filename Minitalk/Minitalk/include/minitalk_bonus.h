/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk_bonus.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: asimone <asimone@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:28:42 by asimone       #+#    #+#                 */
/*   Updated: 2023/05/07 18:10:01 by asimone       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../Libft/include/libft.h"
# include <signal.h>

# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

void	message_handler(int sig);
int		send_message(pid_t pid, char *str);
void	signal_handler(int sig, siginfo_t *client, void *ucontext);

#endif
