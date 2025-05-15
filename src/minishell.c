/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/15 13:02:16 by bgil-fer         ###   ########.fr       */
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
		// aquí va el parsing y ejecución
		//parse_input(&shell, line);
		print_env(shell.env_cpy); //comprobar que lo que le meto es env
		//free_struct(&shell); //no se está creando la estructura shell
		free(line);
	}
	return (EXIT_SUCCESS);
}
