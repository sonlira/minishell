/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:10:56 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/06 23:01:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 34 = "
// 39 = '
static int count_pipe(char *s)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 34)
		{
			i = ft_strchr_idx(s + i, 34); 
	// Falta añadir cositas :/ 
	// ft_strchr_idx() me devuelve el índice del siguiente `"` pero no considera si antes de ese carácter hay un `\`.
	// Por lo tanto, no me sirve tal cual está.
	// Nota: Implementar una función que retorne el índice de la comilla válida, es decir, aquella que no tiene un `\` antes de ella.
	// Idea: Usar un bucle `while` que llame a `ft_strchr_idx` hasta encontrar la comilla de cierre válida.
		}						
		i++;
	}
	return (count);
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
