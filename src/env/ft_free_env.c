/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 00:55:14 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	free_env(char ***env)
{
	size_t	i;

	if (!env || !*env)
		return ;
	i = 0;
	while ((*env)[i])
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
	*env = NULL;
}

void	free_partial_env(char **env, size_t count)
{
	size_t	i;

	if (!env || count <= 0)
		return ;
	i = 0;
	while (i < count)
	{
		free(env[i]);
		i++;
	}
	free(env);
}
