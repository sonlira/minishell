/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:04:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 19:44:36 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	return (!ft_strcmp(cmd, "echo") || \
	!ft_strcmp(cmd, "cd") || \
	!ft_strcmp(cmd, "pwd") || \
	!ft_strcmp(cmd, "export") || \
	!ft_strcmp(cmd, "unset") || \
	!ft_strcmp(cmd, "env") || \
	!ft_strcmp(cmd, "exit"));
}

int	execute_builtin(t_shell *shell, t_cmd *cmd)
{
	if (!ft_strcmp(cmd->cmd, "echo"))
		return (ft_echo(cmd->args));
	if (!ft_strcmp(cmd->cmd, "cd"))
		return (ft_cd(cmd->args, &shell->env_cpy));
	if (!ft_strcmp(cmd->cmd, "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd->cmd, "export"))
		return (ft_export(cmd->args, &shell->env_cpy));
	if (!ft_strcmp(cmd->cmd, "unset"))
		return (ft_unset(cmd->args, &shell->env_cpy));
	if (!ft_strcmp(cmd->cmd, "env"))
		return (ft_env(cmd->args, shell->env_cpy));
	if (!ft_strcmp(cmd->cmd, "exit"))
		return (ft_exit(shell, cmd));
	return (ERROR);
}
