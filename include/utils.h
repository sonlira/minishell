/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/04 19:14:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

bool	init_shell_struct(t_shell *shell, char **envp);
t_cmd	*create_cmd_struct(void);
bool	create_cmd_list(t_shell *shell, size_t size);
void	init_iterator(t_iterator *it);
void	init_cmd_fds(t_cmd_fds *fds);
void	free_struct(t_shell *shell);
void	free_cmd_list(t_shell *shell);
bool	array_push(char ***array, const char *value);
bool	array_unshift(char ***array, const char *value);
bool	dup_str_array_into(char ***dst, char **orig);
bool	bool_array_push(bool **array, const bool value, size_t size);
bool	create_matrix(int ***matrix, size_t rows, size_t cols);
void	free_matrix(int ***matrix, size_t size);

#endif