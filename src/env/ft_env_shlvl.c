/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:39:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/18 19:44:24 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	str_isnumber(char *str)
{
	size_t	i;

	i = 0;
	if (!str[i])
		return (false);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

static bool	is_valid_shlvl_value(int level)
{
	if (level > MAX_SHLVL)
	{
		ft_eprintf("Minishell: warning: ");
		ft_eprintf("shell level (%d) is too high, resetting to 1\n", level);
		return (false);
	}
	return (true);
}

static void	update_shlvl(char ***env, long long level)
{
	char	*new_value;

	level++;
	if (level > INT_MAX || !is_valid_shlvl_value((int)level))
	{
		set_env_var(env, "SHLVL", "1");
		return ;
	}
	new_value = ft_itoa(level);
	if (!new_value)
	{
		set_env_var(env, "SHLVL", "1");
		return ;
	}
	set_env_var(env, "SHLVL", new_value);
	free(new_value);
}

void	validate_and_update_shlvl(char ***env)
{
	char		*old_value;
	long long	level;

	if (!env || !*env)
		return ;
	old_value = get_env_value(*env, "SHLVL");
	if (!old_value)
		return ((void)set_env_var(env, "SHLVL", "1"));
	level = ft_atoi(old_value);
	if (!str_isnumber(old_value) || level == 0)
	{
		set_env_var(env, "SHLVL", "1");
		return (free(old_value));
	}
	if (level < 0)
	{
		set_env_var(env, "SHLVL", "0");
		return (free(old_value));
	}
	free(old_value);
	update_shlvl(env, level);
}
