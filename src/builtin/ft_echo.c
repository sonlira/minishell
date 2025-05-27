/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 23:42:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_only_n_flags(const char *s)
{
	size_t	i;

	i = 0;
	if (s[i++] != '-')
		return (false);
	while (s[i])
	{
		if (s[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	ft_echo(char **args)
{
	bool	flag;
	size_t	i;

	i = 1;
	flag = false;
	while (args[i] && (!ft_strcmp(args[i], "-n") || is_only_n_flags(args[i])))
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
