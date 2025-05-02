/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 11:42:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	echo(char **args)
{
	bool	is_flag;
	size_t	i;

	i = 1;
	is_flag = false;
	while (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		is_flag = true;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (!is_flag)
		printf("\n");
	return (EXIT_OK);
}
