/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:17:28 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 20:01:55 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	process_redir_target(t_shell *shell, t_cmd *cmd, char **str, char *type)
{
	char	*save_arg;


	if (!shell || !cmd || !str || !*str)
		return (false);
	save_arg = ft_strdup(*str);
	if (!save_arg)
		return (false);
	expander_dollar_args(shell, str, true);
	remove_quotes_and_backslashes(shell, str);
	if (!(*str)[0])
		ft_set_string(str, save_arg);
	if (!ft_strcmp(type, ">>") || !ft_strcmp(type, ">"))
		array_push(&cmd->outfile, *str);
	else if (!ft_strcmp(type, "<"))
		array_push(&cmd->infile, *str);
	free(save_arg);
	return (true);
}

bool	process_cmd_arg(t_shell *shell, t_cmd *cmd, char **str)
{
	if (!shell || !cmd || !str || !*str)
		return (false);
	expander_dollar_args(shell, str, true);
	remove_quotes_and_backslashes(shell, str);
	if ((*str)[0])
		array_push(&cmd->args, *str);
	return (true);
}

bool	has_non_whitespace(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == 32)
		i++;
	if (s[i] && s[i] == 34 && s[i + 1] && s[i + 1] == 34)
		return (false);
	else if (s[i] && s[i] == 39 && s[i + 1] && s[i + 1] == 39)
		return (false);
	if (!s[i])
		return (false);
	return (true);
}
