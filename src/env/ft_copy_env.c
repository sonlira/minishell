/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 16:06:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	init_copy(char **dest, const char **orig)
{
	size_t	i;

	if (!orig || !dest)
		return (false);
	i = 0;
	while (orig[i])
	{
		dest[i] = ft_strdup(orig[i]);
		if (!dest[i])
		{
			free_partial_env(dest, i);
			return (false);
		}
		i++;
	}
	return (true);
}

char	**copy_env(const char **envp)
{
	char	**new_env;
	int		size;

	if (!envp || !*envp)
		return (NULL);
	size = ft_count_elements(envp);
	new_env = malloc((size + 1) * sizeof(char *));
	if (!new_env)
		return (NULL);
	new_env[size] = NULL;
	if (!init_copy(new_env, envp))
		return (NULL);
	return (new_env);
}
