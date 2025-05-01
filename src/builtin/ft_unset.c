/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 00:17:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 00:30:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	unset(char **args, char ***env)
{
	size_t	i;

	if (!args[1])
		return (EXIT_OK);
	i = 1;
	while (args[i])
	{
		unset_env_var(env, args[i]);
		i++;
	}
	return (EXIT_OK);
}
