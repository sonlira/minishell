/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/28 21:09:33 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# define BUFF_SIZE 4096

typedef enum e_std
{
	STDIN	= 0,
	STDOUT	= 1,
	STDERR	= 2
}	t_std;
typedef enum e_status
{
	ERROR	= -1,
	FAILURE = 0,
	SUCCESS = 1
}	t_status;

typedef enum e_builtin_status
{
	LIMITER	= 256,
	EXIT_OK	= 0,
	EXIT_KO	= 1, //1 (EXIT_KO) Falla general de ejecución
	INVALID	= 2,
	UNKNOWN_COMMAND = 127, //ENOENT	127	Comando no encontrado
	CMD_NOT_EXECUTABLE = 126, //EACCES, EISDIR	126	No ejecutable / sin permisos
}	t_builtin_status;

typedef enum e_redir
{
	REDIR_NONE,
	REDIR_INFILE,
	REDIR_HEREDOC
}	t_redir;

#endif
