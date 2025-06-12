/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:10:56 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/12 19:25:03 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_quoted_content(const char *s, char *d, size_t *i, size_t *j)
{
	size_t	end;

	end = *i;
	ft_find_rawchar(s, s[*i], &end);
	if (*i + 1 == end)
	{
		*i = end + 1;
		return ;
	}
	while (*i <= end)
		d[(*j)++] = s[(*i)++];
}

static bool	is_operator(int c)
{
	return (c == 59 || c == 60 || c == 62 || c == 124);
}

static void	space_operators(const char *s, char *dst, size_t *i, size_t *j)
{
	dst[(*j)++] = 32;
	while (s[*i] && is_operator(s[*i]))
	{
		if (s[*i] == '<' && s[*i + 1] && s[*i + 1] == '<')
		{
			dst[(*j)++] = s[(*i)++];
			dst[(*j)++] = s[(*i)++];
		}
		else if (s[*i] == '>' && s[*i + 1] && s[*i + 1] == '>')
		{
			dst[(*j)++] = s[(*i)++];
			dst[(*j)++] = s[(*i)++];
		}
		else
			dst[(*j)++] = s[(*i)++];
		dst[(*j)++] = 32;
	}
}

bool	format_prompt_str(t_shell *shell, char **dest, const char *s)
{
	size_t	i;
	size_t	j;
	char	dst[BUFF_SIZE];

	if (!dest || !s || !are_valid_quotes(shell, s))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && !is_operator(s[i]))
		{
			if (s[i] == '$' && s[i + 1] && (s[i + 1] == 34 || s[i + 1] == 39))
				i++;
			else if ((s[i] == 34 || s[i] == 39) && (s[i - 1] || i == 0))
				copy_quoted_content(s, dst, &i, &j);
			else
				dst[j++] = s[i++];
			if (is_operator(s[i]) && s[i - 1] == 92)
				dst[j++] = s[i++];
		}
		space_operators(s, dst, &i, &j);
	}
	dst[j] = 0;
	return (ft_set_string(dest, dst));
}

bool	has_non_whitespace(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == 32)
		i++;
	if (!s[i])
		return (false);
	return (true);
}
