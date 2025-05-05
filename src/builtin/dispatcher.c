/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:04:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 20:26:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	execute_builtin(char **args, char ***envp)
{
	if (!ft_strcmp(args[0], "echo"))
		return (ft_echo(args));
	if (!ft_strcmp(args[0], "cd"))
		return (ft_cd(args, envp));
	if (!ft_strcmp(args[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(args[0], "export"))
		return (ft_export(args, envp));
	if (!ft_strcmp(args[0], "unset"))
		return (ft_unset(args, envp));
	if (!ft_strcmp(args[0], "env"))
		return (ft_env(args, *envp));
	if (!ft_strcmp(args[0], "exit"))
		return (ft_exit(args));
	return (ERROR);
}
