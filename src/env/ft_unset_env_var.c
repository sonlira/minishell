/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:43:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 14:47:53 by abaldelo         ###   ########.fr       */
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

static bool	copy_without_var(char **dest, char **orig, size_t skip_idx)
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
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	delete_var(char ***env, const char *name)
{
	char	**new_env;
	size_t	size;
	int		idx;

	idx = find_name(*env, name);
	if (idx == ERROR)
		return (false);
	size = ft_count_elements((const char **)(*env));
	new_env = malloc(size * sizeof(char *));
	if (!new_env)
		return (false);
	if (!copy_without_var(new_env, *env, idx))
		return (false);
	new_env[size - 1] = NULL;
	free_env(env);
	*env = new_env;
	return (true);
}

bool	unset_env_var(char ***env, const char *name)
{
	if (!env || !*env || !name)
		return (false);
	if (delete_var(env, name))
		return (true);
	return (false);
}
