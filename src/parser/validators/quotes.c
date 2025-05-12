/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:03:02 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/12 18:31:41 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_and_skip_quoted(char *s, int c, size_t i, int *count)
{
	if ((i == 0) || (s[i - 1] && s[i - 1] != 92))
	{
		*count += 1;
		if (ft_find_rawchar(s, c, &i))
			*count += 1;
	}
	return (i);
}

bool	are_valid_quotes(const char *s)
{
	int		quote;
	int		dquote;
	size_t	i;

	i = 0;
	quote = 0;
	dquote = 0;
	while (s[i])
	{
		if (s[i] == 39 && (s[i - 1] || i == 0))
			i = count_and_skip_quoted((char *)s, 39, i, &quote);
		else if (s[i] == 34 && (s[i - 1] || i == 0))
			i = count_and_skip_quoted((char *)s, 34, i, &dquote);
		i++;
	}
	return ((dquote % 2 == 0) && (quote % 2 == 0));
}
