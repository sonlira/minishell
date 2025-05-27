/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:25:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/27 11:23:46 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	syntax_error(t_shell *shell, char **args, size_t i)
{
	char	*str;

	str = args[i];
	if (!str)
		str = "newline";
	ft_eprintf("minishell: syntax error near unexpected token `%s`\n", str);
	shell->last_exit = INVALID;
	ft_free_split(&args);
	return (false);
}

static bool	is_redirection(char *s)
{
	if (!ft_strcmp(s, "<") || !ft_strcmp(s, "<<"))
		return (true);
	if (!ft_strcmp(s, ">") || !ft_strcmp(s, ">>"))
		return (true);
	return (false);
}

static bool	is_operator(char *s)
{
	if (!ft_strcmp(s, "|") || !ft_strcmp(s, ";"))
		return (true);
	return (false);
}

static bool	is_redirection(const char *s)
{
	bool	has_redirection;

	has_redirection = false;
	if (ft_is_rawchar(s, 60))
		has_redirection = true;
	else if (ft_is_rawchar(s, 62))
		has_redirection = true;
	return (has_redirection);
}

bool	are_valid_redirection(t_shell *shell, const char *s)
{
	char	**args;
	size_t	i;

	if (!s)
		return (false);
	if (!is_redirection(s))
		return (true);
	if (!split_ignoring_quotes(shell, s, &args))
		return (false);
	i = 0;
	while (args[i])
	{
		if (is_redirection(args[i++]))
		{
			if (args[i] && is_redirection(args[i]))
				return (syntax_error(shell, args, i));
			else if (args[i] && is_operator(args[i]))
				return (syntax_error(shell, args, i));
			else if (!args[i])
				return (syntax_error(shell, args, i));
		}
	}
	shell->last_exit = EXIT_OK;
	ft_free_split(&args);
	return (true);
}
