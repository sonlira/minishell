/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/06 21:41:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (!init_shell_struct(&shell, envp))
		return (EXIT_FAILURE);
	while (shell.running)
	{
		setup_shell_signals();
		line = readline("minishell> ");
		if (!line)
			handler_eof(&shell, line);
		add_history(line);
		if (parse_input(&shell, line))
			execute_shell_command(&shell);
		free(line);
		free_cmd_list(&shell);
	}
	free_struct(&shell);
	return (EXIT_SUCCESS);
}
