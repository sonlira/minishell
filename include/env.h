/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/18 19:45:15 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

void	free_partial_env(char **env, size_t count);
bool	variable_name_is_equal(char *var, const char *name);
bool	init_copy(char **dest, const char **orig);
char	**copy_env(const char **envp);
void	free_env(char ***env);
char	*get_env_value(char **env, const char *name);
bool	set_env_var(char ***env, const char *name, const char *value);
bool	unset_env_var(char ***env, const char *name);
void	print_env(char **env);
void	print_sorted_env(char **env);
void	validate_and_update_shlvl(char ***env);

#endif