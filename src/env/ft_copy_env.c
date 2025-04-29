/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/04/05 22:51:51 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_count(const char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

static void	free_partial_env(char **env, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

static int	init_copy(char **dest, const char **orig)
{
	size_t	i;

	i = 0;
	while (orig[i])
	{
		dest[i] = ft_strdup(orig[i]);
		if (!dest[i])
		{
			free_partial_env(dest, i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

char	**copy_env(const char **envp)
{
	char	**new_env;
	int		size;

	size = env_count(envp);
	new_env = malloc((size + 1) * sizeof(char *));
	if (!new_env)
		return (NULL);
	new_env[size] = NULL;
	if (!init_copy(new_env, envp))
		return (NULL);
	return (new_env);
}
