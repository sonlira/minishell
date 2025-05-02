/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:53 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 20:26:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUILTIN_H
# define BUILTIN_H

int	echo(char **args);
int	pwd(void);
int	ft_exit(char **args);
int	cd(char **args, char ***env);
int	export(char **args, char ***env);
int	unset(char **args, char ***env);
int	env(char **args, char **env);
int	is_builtin(char *cmd);
int	execute_builtin(char **args, char ***envp);

#endif