/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/15 12:45:56 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

bool	init_shell_struct(t_shell *shell, char **envp);
t_cmd	*create_cmd_struct(void);
bool	matrix_push(char ***matrix, const char *value);
bool	matrix_unshift(char ***matrix, const char *value);
bool	create_cmd_array(t_shell *shell, size_t size);
void	free_struct(t_shell *shell);

#endif