/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:43:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 12:22:31 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_name(char **env, const char *name)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (variable_name_is_equal(env[i], name))
			return (i);
		i++;
	}
	return (ERROR);
}

static int	copy_without_var(char **dest, char **orig, size_t skip_idx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (orig[i])
	{
		if (i != skip_idx)
		{
			dest[j] = ft_strdup(orig[i]);
			if (!dest[j])
			{
				free_partial_env(dest, j);
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	delete_var(char ***env, const char *name)
{
	char	**new_env;
	size_t	size;
	int		idx;

	idx = find_name(*env, name);
	if (idx == ERROR)
		return (FAILURE);
	size = ft_count_elements((const char **)(*env));
	new_env = malloc(size * sizeof(char *));
	if (!new_env)
		return (FAILURE);
	if (!copy_without_var(new_env, *env, idx))
		return (FAILURE);
	new_env[size - 1] = NULL;
	free_env(env);
	*env = new_env;
	return (SUCCESS);
}

int	unset_env_var(char ***env, const char *name)
{
	if (!env || !*env || !name)
		return (FAILURE);
	if (delete_var(env, name))
		return (SUCCESS);
	return (FAILURE);
}
