/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:29:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/01 19:51:48 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

static int	update_oldpwd(char **env, char *value)
{
	char	*cwd;

	if (!set_env_var(env, "OLDPWD", value))
		return (free(value), FAILURE);
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (free(value), FAILURE);
	if (!set_env_var(env, "PWD", cwd))
		return (free(value), free(cwd), FAILURE);
	return (free(value), free(cwd), SUCCESS);
}

static int	go_to_env_path(char **args, char ***env, const char *name)
{
	char	*var;
	char	*pwd;

	var = get_env_value(*env, name);
	if (!var)
	{
		printf("minishell: cd: %s not set\n", name);
		return (FAILURE);
	}
	pwd = get_env_value(*env, "PWD");
	if (!pwd)
		return (free(var), FAILURE);
	if (chdir(var) == ERROR)
		return (free(var), free(pwd), FAILURE);
	update_oldpwd(*env, pwd);
	return (free(var), SUCCESS);
}

static int	go_path(char **args, char ***env)
{
	char	*pwd;

	pwd = get_env_value(*env, "PWD");
	if (!pwd)
		return (FAILURE);
	if (chdir(args[1]) == ERROR)
	{
		printf("minishell: cd: %s ", args[1]);
		printf(": The file or directory does not exist\n");
		return (free(pwd), FAILURE);
	}
	update_oldpwd(*env, pwd);
	return (SUCCESS);
}

int	cd(char **args, char ***env)
{
	int	count;

	count = env_count((const char **)args);
	if (count == 1)
		return (go_to_env_path(args, env, "HOME"));
	else if (count == 2)
	{
		if (ft_strcmp(args[1], "-") == 0)
			return (go_to_env_path(args, env, "OLDPWD"));
		return (go_path(args, env));
	}
	printf("minishell: cd:  too many arguments\n");
	return (FAILURE);
}
