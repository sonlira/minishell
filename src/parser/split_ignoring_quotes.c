/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ignoring_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:10:56 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/12 18:58:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	length_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if ((s[i] == 34 || s[i] == 39) && ft_find_rawchar(s, s[i], &i))
			i++;
		else
			i++;
	}
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s += length_word(s, c);
		}
		else
			s++;
	}
	return (count);
}

bool	split_ignore_quotes(char const *s, char ***matrix)
{
	size_t	i;
	char	c;

	i = 0;
	c = 32;
	if (!s || !matrix || !are_valid_quotes(s))
		return (false);
	*matrix = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!*matrix)
		return (false);
	while (*s)
	{
		if (*s != c)
		{
			(*matrix)[i] = ft_substr(s, 0, length_word(s, c));
			if (!(*matrix)[i++])
				return (ft_free_split(matrix), false);
			s += length_word(s, c);
		}
		else
			s++;
	}
	return (true);
}
