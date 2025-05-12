/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/12 20:53:44 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 34  = "
 39  = '
 124 = |
 92  = \ 
 59 = ;
 60 = <
 62 = >
*/

bool	parser(t_shell *shell, const char *line)
{
	char	*format_str;
	char	**matrix;

	(void)shell;
	if (!are_valid_quotes(line))
		return (false);
	if (!are_valid_semicolon(line) || !are_valid_pipes(line))
		return (false);
	format_str = format_prompt_str(line);
	if (!format_str)
		return (false);
	if (split_valid_semicolons(format_str, &matrix))
	{
		// trabajamos aqui
	}
	else if (split_ignore_quotes(format_str, &matrix))
	{
			// trabajamos aqui;
	}
	free(format_str);
	ft_free_split(&matrix);
	return (true);
}
