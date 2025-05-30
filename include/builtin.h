/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:53 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 19:45:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_echo(char **args);
int	ft_pwd(void);
int	ft_exit(t_shell *shell, t_cmd *cmd);
int	ft_cd(char **args, char ***env);
int	ft_export(char **args, char ***env);
int	ft_unset(char **args, char ***env);
int	ft_env(char **args, char **env);
int	is_builtin(char *cmd);
int	execute_builtin(t_shell *shell, t_cmd *cmd);

#endif