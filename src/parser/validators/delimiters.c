/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:12:33 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/29 22:36:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid_delimiter(t_shell *shell, const char *s, size_t i)
{
	char	c;

	c = s[i];
	if (i == 0 && s[i] == c)
	{
		ft_eprintf("minishell: syntax error near unexpected token `%c`\n", c);
		shell->last_exit = INVALID;
		return (false);
	}
	i++;
	while (ft_isspace(s[i]))
		i++;
	if (!s[i] || s[i] == 124 || s[i] == 59)
	{
		if (s[i])
			c = s[i];
		ft_eprintf("minishell: syntax error near unexpected token `%c`\n", c);
		shell->last_exit = INVALID;
		return (false);
	}
	return (true);
}

bool	are_valid_delims(t_shell *sh, const char *s, int delim, size_t *total)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s || !are_valid_quotes(sh, s))
		return (false);
	while (s[i])
	{
		if ((s[i] == 34 || s[i] == 39) && ft_find_rawchar(s, s[i], &i))
			i++;
		else if (s[i] == (char)delim && s[i - 1] != 92)
		{
			if (!is_valid_delimiter(sh, s, i))
				return (false);
			count++;
			i++;
		}
		else
			i++;
	}
	*total = count;
	return (true);
}

bool	are_valid_pipes(t_shell *shell, const char *s)
{
	return (are_valid_delims(shell, s, 124, &(size_t){0}));
}

bool	are_valid_semicolon(t_shell *shell, const char *s)
{
	return (are_valid_delims(shell, s, 59, &(size_t){0}));
}
