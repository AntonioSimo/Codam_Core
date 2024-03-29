/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimone <asimone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:39 by pskrucha          #+#    #+#             */
/*   Updated: 2023/12/12 18:30:43 by asimone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	strlen_quoted(char *line, int position, t_type quotes_type)
{
	int	length;

	length = 0;
	position++;
	while (line[position + length])
	{
		if (quotes_type == SINGLE_QUOTED && line[position + length] == '\'')
			return (length);
		if (quotes_type == DOUBLE_QUOTED && line[position + length] == '\"')
			return (length);
		length++;
	}
	return (0);
}

t_type	quotes_type(char *line, int pos)
{
	bool	d_quotes;
	bool	s_quotes;
	int		i;

	i = 0;
	d_quotes = true;
	s_quotes = true;
	while (i <= pos)
	{
		if (line[i] == '\'')
			s_quotes = !(s_quotes && d_quotes);
		if (line[i] == '\"')
			d_quotes = !(s_quotes && d_quotes);
		i++;
	}
	if (!d_quotes)
		return (DOUBLE_QUOTED);
	else if (!s_quotes)
		return (SINGLE_QUOTED);
	else
		return (DEFAULT);
}

bool	check_quotes(char *line)
{
	bool	d_quotes;
	bool	s_quotes;

	d_quotes = true;
	s_quotes = true;
	while (*line)
	{
		if (*line == '\'')
			s_quotes = !(s_quotes && d_quotes);
		if (*line == '\"')
			d_quotes = !(s_quotes && d_quotes);
		line++;
	}
	return (d_quotes && s_quotes);
}

void	skip_quotes(char *line, int *i, t_type *quotes)
{
	int	quotted_len;

	quotted_len = strlen_quoted(line, *i, *quotes);
	*i += quotted_len + 2;
	*quotes = DEFAULT;
}
