/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:59:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 14:49:56 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	variable_name_is_equal(char *var, const char *name)
{
	size_t	len;

	if (!var || !name)
		return (false);
	len = ft_strlen(name);
	if (!ft_strncmp(var, name, len) && var[len] == '=')
		return (true);
	return (false);
}

char	*get_env_value(char **env, const char *name)
{
	size_t	i;
	char	*value;

	if (!env || !name)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (variable_name_is_equal(env[i], name))
		{
			value = ft_strdup(ft_strchr(env[i], '=') + 1);
			return (value);
		}
		i++;
	}
	return (NULL);
}
