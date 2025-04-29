/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-29 12:48:59 by abaldelo          #+#    #+#             */
/*   Updated: 2025-04-29 12:48:59 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	variable_name_is_equal(char *var, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (!ft_strncmp(var, name, len) && var[len] == '=')
		return (SUCCESS);
	return (FAILURE);
}

static void	update_value(char *var, char *name, char *value)
{
	char	*result;
	char	*new_value;

	free(var);
	result = ft_strjoin(name, '=');
	new_value = ft_strjoin(result, value);
	free(result);
	var = new_value;
	free(new_value);
}

//static  add_var()

int	set_env_var(char ***env, const char *name, const char *value)
{
	size_t	i;

	while ((*env)[i])
	{
		if (variable_name_is_equal((*env)[i], name))
		{
			update_value((*env)[i], name, value);
			return (SUCCESS);
		}
		i++;
	}
		// add_var()
		// Incompleto...
	return (FAILURE);
}
