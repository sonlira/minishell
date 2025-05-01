/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:14:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 00:39:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	env(char **args, char **env)
{
	if (!args[1])
	{
		print_env(env);
		return (SUCCESS);
	}
	printf("env: «%s»", args[1]);
	printf(": No such file or directory\n");
	return (UNKNOWN_COMMAND);
}
