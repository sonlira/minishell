/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:48:56 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 18:40:36 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	size_t	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			printf("%s\n", env[i]);
		i++;
	}
}
