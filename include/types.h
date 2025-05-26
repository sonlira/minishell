/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:00:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 19:44:19 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_cmd
{
	char			*cmd; // Nombre del comando (ej: "ls")
	char			**args; //  Argumentos del comando (ej: {"ls", "-l", NULL})
	char			*infile; // Redirección de entrada (ej: "< input.txt")
	char			**outfile; // Redirección de salida (ej: "> output.txt")
	bool			append; // 1 si es >>, 0 si es >
	bool			heredoc; // 1 si el token es '<<' (heredoc), 0 si no
	char			*delimiter; // delimitador del heredoc (ej: "EOF")
	bool			is_quoted;//1 si el delimitador está entre comillas, 0 si no
	struct s_cmd	*next; // Apunta al siguiente comando (en caso de pipes)
	struct s_cmd	*prev; // punta al anterior comando (en caso de pipes)
}	t_cmd;

typedef struct s_shell
{
	char	**env_cpy; // Copia modificable de las variables de entorno
	int		last_exit; // Último código de salida ($?)
	bool	running; // Flag para saber si la shell debe seguir ejecutándose
	t_cmd	**cmd_list; // Lista enlazada de comandos parseados
}	t_shell;

typedef struct s_iterator
{
	size_t	i;
	size_t	j;
	size_t	k;
}	t_iterator;

#endif
