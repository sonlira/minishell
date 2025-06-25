/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:59:19 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 18:45:28 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_validname(char *name)
{
	size_t	i;

	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (false);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

static int	export_vars(char **args, char ***env)
{
	char	**var;
	size_t	i;
	int		error;

	i = 1;
	error = 0;
	while (args[i])
	{
		var = ft_split(args[i], '=');
		if (!var)
			return (EXIT_KO);
		if (!is_validname(var[0]) || args[i][0] == '=')
		{
			ft_eprintf("minishell: export: ");
			ft_eprintf("%s: is not a valid identifier\n", args[i]);
			error++;
		}
		else if (ft_strchr(args[i], '=') && !var[1])
			set_env_var(env, var[0], "");
		else
			set_env_var(env, var[0], var[1]);
		ft_free_split(&var);
		i++;
	}
	return (error != 0);
}

int	ft_export(char **args, char ***env)
{
	if (!args[1] || !args[1][0])
	{
		print_sorted_env(*env);
		return (EXIT_OK);
	}
	return (export_vars(args, env));
}
