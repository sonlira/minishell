/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 20:57:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// volatile sig_atomic_t g_signal = 0;

int	main(int argc, char **argv, char **envp) // falta implementar señales
{
	char	*line;
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (!init_shell_struct(&shell, envp))
		return (EXIT_FAILURE);
	setup_shell_signals();
	while (shell.running)
	{
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
