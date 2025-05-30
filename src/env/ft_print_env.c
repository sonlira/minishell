/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:48:56 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:20:08 by abaldelo         ###   ########.fr       */
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
		printf("%s\n", env[i]);
		i++;
	}
}
