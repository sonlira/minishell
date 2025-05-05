/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:29:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:30:42 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_oldpwd(char ***env, char *value)
{
	char	*cwd;

	if (!set_env_var(env, "OLDPWD", value)) //set_env_var actualiza en mi copia de env, la rut en la variable OLDPWD
		return (free(value), FAILURE);
	cwd = getcwd(NULL, 0); //me da la ruta actual (pwd)
	if (!cwd)
		return (free(value), FAILURE);
	if (!set_env_var(env, "PWD", cwd))
		return (free(value), free(cwd), FAILURE);
	return (free(value), free(cwd), SUCCESS);
}

static int	go_to_env_path(char ***env, const char *name)
{
	char	*var;
	char	*pwd;

	var = get_env_value(*env, name);
	if (!var)
	{
		ft_printf_error("minishell: cd: %s not set\n", name);
		return (EXIT_KO);
	}
	pwd = get_env_value(*env, "PWD");
	if (!pwd)
		return (free(var), EXIT_KO);
	if (chdir(var) == ERROR) // chdir cambia de ruta
		return (free(var), free(pwd), EXIT_KO);
	update_oldpwd(env, pwd);
	return (free(var), EXIT_OK);
}

static int	go_path(char **args, char ***env)
{
	char	*pwd;

	pwd = get_env_value(*env, "PWD");
	if (!pwd)
	{
		pwd = getcwd(NULL, 0);
		if (!pwd)
			return (EXIT_KO);
	}
	if (chdir(args[1]) == ERROR)
	{
		ft_printf_error("minishell: cd: %s ", args[1]);
		ft_printf_error(": The file or directory does not exist\n");
		return (free(pwd), EXIT_KO);
	}
	update_oldpwd(env, pwd);
	free(pwd);
	return (EXIT_OK);
}

int	ft_cd(char **args, char ***env)
{
	int	count;

	count = count_elements((const char **)args);
	if (count == 1)
		return (go_to_env_path(env, "HOME"));
	else if (count == 2)
	{
		if (ft_strcmp(args[1], "-") == 0) // Si -, vuelve a la ruta anterior
			return (go_to_env_path(env, "OLDPWD"));
		return (go_path(args, env));
	}
	ft_printf_error("minishell: cd:  too many arguments\n");
	return (EXIT_KO);
}
