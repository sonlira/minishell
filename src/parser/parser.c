/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/09 20:28:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 34 = "
// 39 = '

int parser(t_shell *shell, char *line)
{
    (void)shell;
	size_t pipes;
	pipes = 0;
	if (!count_valid_pipes(line, &pipes))
		printf("pipes no validas\n");
	else
    	printf("pipes válidas: %ld\n", pipes);
    printf("comillas válidas: %d\n", are_valid_quotes(line));
	char **matrix;
	printf("Dividir line\n");
	div_line(line, &matrix);
	ft_free_split(&matrix);
    return (0);
}
