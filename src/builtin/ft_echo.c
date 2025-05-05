/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:14:04 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args)
{
	bool	flag;
	size_t	i;

	i = 1;
	flag = false;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		flag = true;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (EXIT_OK);
}
