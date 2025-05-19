/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 17:56:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

bool	init_shell_struct(t_shell *shell, char **envp);
t_cmd	*create_cmd_struct(void);
bool	create_cmd_list(t_shell *shell, size_t size);
void	free_struct(t_shell *shell);
void	free_cmd_list(t_shell *shell);
bool	array_push(char ***array, const char *value);
bool	array_unshift(char ***array, const char *value);

#endif