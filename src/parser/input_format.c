/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:10:56 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/12 18:21:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_quoted_content(const char *s, char *d, size_t *i, size_t *j)
{
	size_t	end;

	end = *i;
	ft_find_rawchar(s, s[*i], &end);
	while (*i <= end)
	{
		d[*j] = s[*i];
		*i += 1;
		*j += 1;
	}
}

static bool	is_operator(int c)
{
	return (c == 59 || c == 60 || c == 62 || c == 124);
}

char	*format_prompt_str(const char *s)
{
	size_t	i;
	size_t	j;
	char	dst[BUFF_SIZE];

	if (!s || !are_valid_quotes(s))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && !is_operator(s[i]))
		{
			if ((s[i] == 34 || s[i] == 39) && (s[i - 1] || i == 0))
				copy_quoted_content(s, dst, &i, &j);
			else
				dst[j++] = s[i++];
		}
		dst[j++] = 32;
		while (s[i] && is_operator(s[i]))
			dst[j++] = s[i++];
		dst[j++] = 32;
	}
	dst[j] = 0;
	return (ft_strdup(dst));
}
