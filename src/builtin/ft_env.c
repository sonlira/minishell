/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:14:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 15:00:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	env(char **args, char **env)
{
	if (!args[1])
	{
		print_env(env);
		return (EXIT_OK);
	}
	ft_printf_error("env: «%s»", args[1]);
	ft_printf_error(": No such file or directory\n");
	return (UNKNOWN_COMMAND);
}
