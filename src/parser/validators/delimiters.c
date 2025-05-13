/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:12:33 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 22:39:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static bool	is_valid_delimiter(const char *s, size_t i)
{
	if (i == 0 && s[i] == 124)
	{
		ft_printf_error("minishell: syntax error near unexpected token '|'\n");
		return (false);
	}
	if (i == 0 && s[i] == 59)
	{
		ft_printf_error("minishell: syntax error near unexpected token ';'\n");
		return (false);
	}
	i++;
	while (ft_isspace(s[i]))
		i++;
	return (s[i] != '\0' && s[i] != 124 && s[i] != 59);
}

bool	are_valid_delimiters(const char *s, int delimiter, size_t *total)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s || !are_valid_quotes(s))
		return (false);
	while (s[i])
	{
		if ((s[i] == 34 || s[i] == 39) && ft_find_rawchar(s, s[i], &i))
			i++;
		else if (s[i] == (char)delimiter && s[i - 1] != 92)
		{
			if (!is_valid_delimiter(s, i))
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

bool	are_valid_pipes(const char *s)
{
	return (are_valid_delimiters(s, 124, &(size_t){0}));
}

bool	are_valid_semicolon(const char *s)
{
	return (are_valid_delimiters(s, 59, &(size_t){0}));
}
