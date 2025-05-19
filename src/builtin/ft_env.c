/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:14:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 19:01:36 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **args, char **env)
{
	if (!args[1])
	{
		print_env(env);
		return (EXIT_OK);
	}
	ft_eprintf("env: «%s»", args[1]);
	ft_eprintf(": No such file or directory\n");
	return (UNKNOWN_COMMAND);
}
