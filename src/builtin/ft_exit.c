/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:47:23 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 19:47:50 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(t_shell *shell, t_cmd *cmd)
{
	int	count;
	int	exit_code;

	count = ft_count_elements((const char **)cmd->args);
	printf("exit\n");
	if (count == 1 || (count == 2 && ft_strcmp(cmd->args[1], "0") == 0))
	{
		free_struct(shell);
		exit(EXIT_OK);
	}
	else if (count == 2)
	{
		if (!ft_atoll(cmd->args[1]))
		{
			ft_eprintf("minishell: exit: %s ", cmd->args[1]);
			ft_eprintf(": numeric argument required\n");
			free_struct(shell);
			exit(INVALID);
		}
		exit_code = (int)(ft_atoll(cmd->args[1]) % LIMITER);
		free_struct(shell);
		exit(exit_code);
	}
	ft_eprintf("minishell: exit:  too many arguments\n");
	return (EXIT_KO);
}
