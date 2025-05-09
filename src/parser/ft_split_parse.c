/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:10:56 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/09 21:07:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 34  = "
 39  = '
 124 = |
 92  = \ 
*/

bool	is_valid(const char *s, size_t i) //Cambiar nombre de función
{
	if (i == 0 && s[i] == 124)
	{
		ft_printf_error("minishell: syntax error near unexpected token '|'\n");
		return (false);
	}
	i++;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0' || s[i] == 124)
		return (false);
	return (true);
}

bool	count_valid_pipes(const char *s, size_t *pipes) //Cambiar nombre de función
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 34 && ft_strchr_idx(s, 34, &i))
			i++;
		else if (s[i] == 39 && ft_strchr_idx(s, 39, &i))
			i++;
		else if (s[i] == 124 && s[i - 1] != 92)
		{
			if (!is_valid(s, i))
				return (false);
			count++;
			i++;
		}
		else
			i++;
	}
	*pipes = count;
	return (true);
}

size_t prov	(char *s, int c, size_t i, int *count) //Cambiar nombre de función
{
	if ((i == 0) || (s[i - 1] && s[i - 1] != 92))
	{
		*count += 1;
		if (ft_strchr_idx(s, c, &i))
			*count += 1;
	}
	return (i);
}

int	are_valid_quotes(const char *s)
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
			i = prov((char *)s, 39, i, &quote);
		else if (s[i] == 34 && (s[i - 1] || i == 0))
			i = prov((char *)s, 34, i, &dquote);
		i++;
	}
	printf("quote: %i\n", quote);
	printf("dquote: %i\n", dquote);
	printf("%i mod 2  = %i\n",(quote + dquote) , ((quote + dquote) % 2));
	return ((dquote % 2 == 0) && (quote % 2 == 0));
}

size_t	idx_valid_pipe(char *s, size_t i) //Cambiar nombre de función
{
	while (s[i])
	{
		if (s[i] == 34 && ft_strchr_idx(s, 34, &i))
			i++;
		else if (s[i] == 39 && ft_strchr_idx(s, 39, &i))
			i++;
		else if (s[i] == 124 && s[i - 1] != 92)
			return (i);
		else
			i++;
	}
	return (i);
}

bool	div_line(const char *s, char ***matrix) //Cambiar nombre de función
{
	size_t	size;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!count_valid_pipes(s, &size))
		return (false);
	*matrix = malloc((size + 2) * sizeof(char *));
	if (!*matrix)
		return (false);
	i = -1;
	start = 0;
	while (++i < (size + 1))
	{
		end = idx_valid_pipe((char *)s, start);
		(*matrix)[i] = ft_substr(s, start, (end - start));
		if (!(*matrix)[i])
			return (ft_free_split(matrix), false);
		if (s[end])
			start = end + 1;
		printf("matrix[%zi] %s\n", i, (*matrix)[i]);
	}
	(*matrix)[size + 1] = NULL;
	return (true);
}
// Por ahora, Los Rechazados :,(
static size_t	quoted_words(char const *s, int q) //Revisar
{
	char	*quote;
	size_t	size;

	size = 0;
	quote = NULL;
	quote = ft_strchr(s, q);
	if (ft_count_char(s, q) % 2 == 0)
		quote++;
	while (quote[size] && quote[size] != q)
		size++;
	return (size);
}

static size_t	length_word(char const *s, char c)
{
	size_t	size;
	int		quote_ascii;
	int		quotes;

	size = 0;
	quotes = 0;
	quote_ascii = 0;
	while (s[size] && s[size] != c) // Revisar
	{
		if (s[size] == 39)
			quote_ascii = 39;
		else if (s[size] == 34)
			quote_ascii = 34;
		if (quote_ascii != 0)
		{
			size = quoted_words(s, quote_ascii);
			quotes++;
			quote_ascii = 0;
		}
		size++;
	}
	return (size - quotes);
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

char	**ft_split_parse(char const *s, char c)
{
	char	**words;
	size_t	ntwords;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ntwords = count_words(s, c);
	words = (char **)malloc((ntwords + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			words[i] = ft_substr(s, 0, length_word(s, c));
			if (!words[i++])
				return (ft_free_split(&words), NULL);
			s += length_word(s, c);
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
