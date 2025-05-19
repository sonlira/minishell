/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 15:30:48 by abaldelo         ###   ########.fr       */
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
		line = readline("minishell> ");
		if (!line)
			break ; // Ctrl+D
		add_history(line);
		parse_input(&shell, line);
		// aquí va la ejecución
		free(line);
		free_cmd_list(&shell);
	}
	free_struct(&shell);
	return (EXIT_SUCCESS);
}
