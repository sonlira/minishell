/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:39:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/05 22:48:30 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/include/libft.h"
# include "include/parser.h"
# include "include/executor.h"
# include "include/env.h"
# include "include/utils.h"
# include "include/builtin.h"
# include "include/signals.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_cmd
{
	char			*cmd; // Nombre del comando (ej: "ls")
	char			**args; //  Argumentos del comando (ej: {"ls", "-l", NULL})
	char			*infile; // Redirección de entrada (ej: "< input.txt")
	char			*outfile; // Redirección de salida (ej: "> output.txt")
	int				append; // 1 si es >>, 0 si es >
	int				heredoc; // 1 si es <<, 0 si no
	struct s_cmd	*next; // Apunta al siguiente comando (en caso de pipes)
}	t_cmd;

typedef struct s_shell
{
	char	**envp; // Copia modificable de las variables de entorno
	int		last_exit; // Último código de salida ($?)
	int		running; // Lista enlazada de comandos parseados
	t_cmd	*cmd_list; // Flag para saber si la shell debe seguir ejecutándose
}	t_shell;

// Falta contenido... 

#endif