/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/08 13:57:48 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

// 34 = "
// 39 = '

int parser(t_shell *shell, char *line)
{
    (void)shell;
    printf("pipes válidas: %d\n", count_valid_pipe(line));
    printf("comillas válidas: %d\n", are_valid_quotes(line));
    return (0);
}
