/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:10:56 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/08 14:50:32 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

// 34 = "
// 39 = '

int count_valid_pipe(char *s)
{
	int		pipes;
	size_t	i;

	pipes = 0;
	i = 0;
	if (s[0] == 124)
		ft_printf_error("minishell: syntax error near unexpected token '|'");
	while (s[i])
	{
		if (s[i] == 34)
			i = ft_strchr_idx(s, 34, i) + 1;
		else if (s[i] == 39)
			i = ft_strchr_idx(s, 39, i) + 1;
		else if (s[i] == '|' && (s[i - 1] && s[i - 1] != '\\'))
		{
			pipes++;
			i++;
		}
		else
			i++;
	}
	return (pipes);
}

size_t prov (char *s, int c, size_t i, int *count) //Cambiar nombre de función
{
	size_t aux;
	aux = i;
	if (s[i] == c && (s[i - 1] || i == 0))
		{
			if ((i == 0) || (s[i - 1] && s[i - 1] != 92))
			{
				aux = i;
				*count+=1;
				i = ft_strchr_idx(s, c, i);
				if (s[i] == c && i != aux && s[i - 1] != 92)
					*count+=1;
			}
		}
	return (i);
}

int are_valid_quotes(char *s)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 39 && (s[i - 1] || i == 0))
			i = prov(s, 39, i, &count);
		else if (s[i] == 34 && (s[i - 1] || i == 0))
			i = prov(s, 34, i, &count);
		i++;
	}
	printf("quotes: %i\n", count);
	return (count % 2 == 0);
}

int idx_valid_pipe(char *s) // Revisar
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 34 && (s[i - 1] && s[i - 1] != '\\'))
			i = ft_strchr_idx(s, 34, i);
		else if (s[i] == 39 && (s[i - 1] && s[i - 1] != '\\'))
			i = ft_strchr_idx(s, 39, i);
		else if (s[i] == '|' && (s[i - 1] && s[i - 1] != '\\'))
			return (i);
		i++;
	}
	return (i - 1);
}

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
