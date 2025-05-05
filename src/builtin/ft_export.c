/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:59:19 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:13:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_validname(char *name)
{
	size_t	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (FAILURE);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	export_vars(char **agrs, char ***env)
{
	char	**var;
	size_t	i;
	int		error;

	i = 0;
	error = 0;
	while (agrs[i])
	{
		if (!is_validname(agrs[i]))
		{
			printf("minishell: export: %s: is not a valid identifier", agrs[i]);
			error++;
		}
		else
		{
			var = ft_split(agrs[i], '=');
			if (!var)
				return (EXIT_KO);
			set_env_var(env, var[0], var[1]);
			ft_free_split(&var);
		}
		i++;
	}
	return (error != 0);
}

int	ft_export(char **args, char ***env)
{
	if (!args[1])
	{
		print_sorted_env(*env);
		return (EXIT_OK);
	}
	return (export_vars((args + 1), env));
}
