/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/20 17:14:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t g_status = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (!init_shell_struct(&shell, envp))
		return (EXIT_FAILURE);
	validate_and_update_shlvl(&shell.env_cpy);
	while (shell.running)
	{
		setup_shell_signals();
		line = readline("minishell> ");
		if (g_status)
			shell.last_exit = g_status;
		if (!line)
			handler_eof(&shell, line);
		if (line[0])
			add_history(line);
		if (line[0] && parse_input(&shell, line))
			execute_shell_command(&shell);
		free(line);
		free_cmd_list(&shell);
		g_status = 0;
	}
	return (EXIT_SUCCESS);
}
