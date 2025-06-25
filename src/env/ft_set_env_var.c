/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:48:59 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 20:51:04 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*format(const char *name, const char *var_name)
{
	char	*f_name;
	char	*result;

	if (!var_name)
		return (ft_strdup(name));
	f_name = ft_strjoin(name, "=");
	result = ft_strjoin(f_name, var_name);
	if (!result)
		return (f_name);
	free(f_name);
	return (result);
}

static bool	update_value(char ***env, const char *name, char *new_var)
{
	size_t	i;

	i = 0;
	while ((*env)[i])
	{
		if (variable_name_is_equal((*env)[i], name) ||\
		!ft_strcmp((*env)[i], name))
		{
			if (!ft_strcmp(name, new_var)) // Si nome y new_var son iguales no actualizar a sin valor
				return (true);
			free((*env)[i]);
			(*env)[i] = new_var;
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	add_var(char ***env, char *new_var)
{
	char	**new_env;
	int		size;

	size = ft_count_elements((const char **)(*env));
	new_env = malloc((size + 2) * sizeof(char *));
	if (!new_env)
		return (false);
	if (!init_copy(new_env, (const char **)(*env)))
		return (false);
	new_env[size] = new_var;
	new_env[size + 1] = NULL;
	free_env(env);
	*env = new_env;
	return (true);
}

bool	set_env_var(char ***env, const char *name, const char *value)
{
	char	*new_var;

	if (!env || !*env || !name)
		return (false);
	new_var = format(name, value);
	if (!new_var)
		return (false);
	if (update_value(env, name, new_var))
		return (true);
	if (add_var(env, new_var))
		return (true);
	free(new_var);
	return (false);
}
