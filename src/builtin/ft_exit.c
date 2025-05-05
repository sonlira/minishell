/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:47:23 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:30:42 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **args)
{
	int	count;
	int	exit_code;

	count = count_elements((const char **)args);
	printf("exit\n");
	if (count == 1 || (count == 2 && ft_strcmp(args[1], "0") == 0))
		exit(EXIT_OK);
	else if (count == 2)
	{
		if (!ft_atoll(args[1]))
		{
			ft_printf_error("minishell: exit: %s ", args[1]);
			ft_printf_error(": numeric argument required\n");
			exit(INVALID);
		}
		exit_code = (int)(ft_atoll(args[1]) % LIMITER);
		exit(exit_code);
	}
	ft_printf_error("minishell: exit:  too many arguments\n");
	return (EXIT_KO);
}
