/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/07 17:02:29 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 34 = "
// 39 = '

int parser(t_shell *shell, char *line)
{
    int count_quoted_d;
    int count_quoted_s;

    count_quoted_s = ft_count_unescaped_char(line, 39);
    count_quoted_d = ft_count_unescaped_char(line, 34);
    if (count_quoted_d % 2 != 0 || count_quoted_s % 2 != 0)
    {
        ft_printf_error("mensaje de error relacionado con no cerra comillas :O");
        return (ERROR);
    }
    //falta contenido pensaba algo relacionado con las pipes
    // if si hay pipe dividir la line
    // else trabajar con la misma line
}
