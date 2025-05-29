/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_quotes_and_bslash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:01:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/28 20:18:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	proc_dquote(const char *s, char *d, t_iterator *it)
{
	size_t	end;

	end = it->i;
	ft_find_rawchar(s, s[it->i++], &end);
	while (it->i < end)
	{
		if (s[it->i] == '\\' && s[it->i + 1] && s[it->i + 1] != 32)
		{
			it->i++;
			d[it->j++] = s[it->i++];
		}
		else
			d[it->j++] = s[it->i++];
	}
}

static void	backslash_clean(const char *s, char *d, t_iterator *it)
{
	if (s[it->i] == '\\' && s[it->i + 1] && s[it->i + 1] != 32)
	{
		it->i++;
		d[it->j++] = s[it->i++];
	}
	else if (s[it->i] == '\\' && !s[it->i + 1])
	{
		d[it->j++] = 32;
		it->i++;
	}
}

bool	remove_quotes_and_backslashes(t_shell *shell, char **s)
{
	t_iterator	it;
	char		dst[BUFF_SIZE];
	size_t		end;

	if (!s || !*s || !are_valid_quotes(shell, *s))
		return (false);
	init_iterator(&it);
	while ((*s)[it.i])
	{
		if ((*s)[it.i] == 34 && ((*s)[it.i - 1] || it.i == 0))
			proc_dquote(*s, dst, &it);
		else if ((*s)[it.i] == 39 && ((*s)[it.i - 1] || it.i == 0))
		{
			end = it.i;
			ft_find_rawchar(*s, (*s)[it.i++], &end);
			while (it.i < end)
				dst[it.j++] = (*s)[it.i++];
		}
		else if ((*s)[it.i] == 92)
			backslash_clean(*s, dst, &it);
		else
			dst[it.j++] = (*s)[it.i++];
	}
	return (dst[it.j] = 0, ft_set_string(s, dst));
}
