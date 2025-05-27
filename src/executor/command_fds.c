/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:45:18 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/27 13:07:43 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	prov_infile_fd(t_cmd *cmd, int *fd)
{
   return (true); 
}

bool    prov_outfile_fd(t_cmd *cmd, int *fd)
{
    return (true);
}

bool    prov_heredoc_fd(t_cmd *cmd, int *fd)
{
    int pipes[2];

    if (pipe(pipes))
        
    return (true);
}