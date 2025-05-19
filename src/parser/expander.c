/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:48:41 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 20:01:40 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expander_dquote(char *s, char *d, t_iterator *it, t_shell *shell)
{
	size_t	i;
	size_t	end;
	char	*str;

	end = it->i;
	ft_find_rawchar(s, s[it->i], &end);
	str = ft_substr(s, it->i, (end - it->i));
	if (ft_has_rawchar(str, '$'))
	{
		i = 0;
		expander_dollar_args(shell, &str, false);
		while (str[i])
			d[it->j++] = str[i++];
		free(str);
		it->i = end;
	}
	else
	{
		while (it->i <= end)
			d[it->j++] = s[it->i++];
	}
}

static void	expander_dollar(const char *s, char *d, t_iterator *it, t_shell *sh)
{
	t_iterator	iter;
	char		name[BUFF_SIZE];
	char		*value;

	iter.i = 0;
	iter.j = 0;
	if (s[++it->i] == '?')
	{
		value = ft_itoa(sh->last_exit);
		while (value && value[iter.i])
			d[it->j++] = value[iter.i++];
		it->i++;
	}
	else
	{
		while (s[it->i] && (ft_isalnum(s[it->i]) || s[it->i] == '_'))
			name[iter.j++] = s[it->i++];
		name[iter.j] = 0;
		value = get_env_value(sh->env_cpy, name);
		while (value && value[iter.i])
			d[it->j++] = value[iter.i++];
	}
	if (value)
		free(value);
}

static void	is_quoted_prov(char *s, char *d, t_iterator *it, t_shell *shell)
{
	size_t	end;

	if (s[it->i] == 34 && (s[it->i - 1] || it->i == 0))
		expander_dquote(s, d, it, shell);
	else if (s[it->i] == 39 && (s[it->i - 1] || it->i == 0))
	{
		end = it->i;
		ft_find_rawchar(s, s[it->i], &end);
		while (it->i <= end)
			d[it->j++] = s[it->i++];
	}
}

bool	expander_dollar_args(t_shell *shell, char **s, bool quote)
{
	t_iterator	it;
	char		dst[BUFF_SIZE];

	if (!s || (quote && !are_valid_quotes(shell, *s)))
		return (NULL);
	if ((*s)[0] != '$' && !ft_has_rawchar(*s, '$'))
		return (false);
	it.i = 0;
	it.j = 0;
	while ((*s)[it.i])
	{
		if (quote == true && ((*s)[it.i] == 34 || (*s)[it.i] == 39))
			is_quoted_prov(*s, dst, &it, shell);
		else if ((*s)[it.i] == 92 && (*s)[it.i + 1])
		{
			dst[it.j++] = (*s)[it.i++];
			dst[it.j++] = (*s)[it.i++];
		}
		else if ((*s)[it.i] == '$' && (*s)[it.i + 1] && (*s)[it.i + 1] != '$')
			expander_dollar(*s, dst, &it, shell);
		else
			dst[it.j++] = (*s)[it.i++];
	}
	return (dst[it.j] = 0, ft_set_string(s, dst));
}
