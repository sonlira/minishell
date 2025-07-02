/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:55:46 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/29 19:25:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_command_empty(t_cmd *cmd)
{
	if (!cmd || cmd->args)
		return (false);
	if (cmd->outfile || cmd->infile || !cmd->cmd)
	{
		array_push(&cmd->args, "echo");
		array_push(&cmd->args, "-n");
	}
	else if (cmd->heredoc)
		array_push(&cmd->args, "cat");
	return (true);
}

static bool	parse_cmd_value(t_cmd *cmd)
{
	size_t	size;
	size_t	i;
	char	**new_args;

	if (!cmd || !cmd->cmd)
		return (false);
	size = ft_count_words(cmd->cmd, 32);
	if (size == 1)
		return (true);
	new_args = ft_split(cmd->cmd, 32);
	if (!new_args)
		return (false);
	i = 1;
	while (cmd->args[i])
	{
		if (!array_push(&new_args, cmd->args[i++]))
			return (ft_free_split(&new_args), false);
	}
	ft_free_split(&cmd->args);
	cmd->args = new_args;
	return (ft_set_string(&cmd->cmd, cmd->args[0]));
}

bool	validate_and_parse_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (false);
	if (is_command_empty(cmd))
		return (ft_set_string(&cmd->cmd, cmd->args[0]));
	if (!ft_set_string(&cmd->cmd, cmd->args[0]))
		return (false);
	if (parse_cmd_value(cmd))
		return (true);
	return (true);
}

//void	unquote_and_expand(t_shell *shell, t_cmd *cmd, char *str)