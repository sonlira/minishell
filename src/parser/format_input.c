/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:10:56 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 20:10:41 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_quoted_content(const char *s, char *d, size_t *i, size_t *j)
{
	size_t	end;
	bool	skip_quoted;

	end = *i;
	skip_quoted = false;
	ft_find_rawchar(s, s[*i], &end);
	if (*i + 1 == end && *i > 0 && ft_isspace(s[*i - 1]))
		skip_quoted = true;
	else if (*i + 1 == end && s[end + 1] && ft_isspace(s[end + 1]))
		skip_quoted = true;
	else if (*i + 1 == end && !s[end + 1])
		skip_quoted = true;
	if (skip_quoted)
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

static void	copy_quote_spaces(const char *s, char *d, size_t *i, size_t *j)
{
	bool	should_quote_space;

	should_quote_space = false;
	if (*i > 1 && s[*i - 1] == 34 && s[*i - 2] == 34)
		should_quote_space = true;
	else if (*i > 1 && s[*i - 1] == 39 && s[*i - 2] == 39)
		should_quote_space = true;
	if (ft_isspace(s[*i]) && should_quote_space)
	{
		d[(*j)++] = 32; // poner espacio
		d[(*j)++] = 34; // abrir comilla simple "'"
		d[(*j)++] = s[(*i)++]; // guardar el espacio
		d[(*j)++] = 34; // cerrar comilla simple "'". Espacio protegido, oh yeah!
		d[(*j)++] = 32; // poner espacio
	}
	else
		d[(*j)++] = s[(*i)++];
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
			else if ((s[i] == 34 || s[i] == 39))
				copy_quoted_content(s, dst, &i, &j);
			else
				copy_quote_spaces(s, dst, &i, &j);
			if (is_operator(s[i]) && i > 0 && s[i - 1] == 92)
				dst[j++] = s[i++];
		}
		space_operators(s, dst, &i, &j);
	}
	dst[j] = 0;
	return (ft_set_string(dest, dst));
}
