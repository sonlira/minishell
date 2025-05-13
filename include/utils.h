/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 19:44:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

bool	init_shell_struct(t_shell *shell, char **envp);
t_cmd	*create_cmd_struct(void);
bool	matrix_push(char ***matrix, const char *value);
bool	matrix_unshift(char ***matrix, const char *value);

#endif