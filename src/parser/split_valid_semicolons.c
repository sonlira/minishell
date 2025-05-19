/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_valid_semicolons.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:05:01 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 19:55:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	count_valid_semicolon(t_shell *shell, const char *s, size_t *size)
{
	return (are_valid_delims(shell, s, 59, size));
}

static size_t	find_next_valid_semicolon_idx(const char *s, size_t i)
{
	while (s[i])
	{
		if ((s[i] == 34 || s[i] == 39) && ft_find_rawchar(s, s[i], &i))
			i++;
		else if (s[i] == 59 && s[i - 1] != 92)
			return (i);
		else
			i++;
	}
	return (i);
}

bool	split_valid_semicolons(t_shell *shell, const char *s, char ***matrix)
{
	size_t	size;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s || !matrix || !are_valid_quotes(shell, s))
		return (false);
	if (!count_valid_semicolon(shell, s, &size))
		return (false);
	*matrix = ft_calloc((size + 2), sizeof(char *));
	if (!*matrix)
		return (false);
	i = -1;
	start = 0;
	while (++i < (size + 1))
	{
		end = find_next_valid_semicolon_idx(s, start);
		(*matrix)[i] = ft_substr(s, start, (end - start));
		if (!(*matrix)[i])
			return (ft_free_split(matrix), false);
		if (s[end])
			start = end + 1;
	}
	return (true);
}
