/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:45:18 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/06/25 18:53:33 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ambiguous_redirect(char *file)
{
	if (ft_strchr(file, '$'))
	{
		ft_eprintf("minishell: %s: ambiguous redirect\n", file);
		return (true);
	}
	return (false);
}

bool	open_infile_if_needed(t_cmd *cmd, int *fd)
{
	size_t	i;

	if (!cmd || !fd)
		return (false);
	i = 0;
	while (cmd->infile[i])
	{
		if (*fd >= 0)
			close(*fd);
		if (ambiguous_redirect(cmd->infile[i]))
			return (false);
		*fd = open(cmd->infile[i], O_RDONLY);
		if (*fd < 0)
		{
			ft_eprintf("minishell: %s: %s\n", cmd->infile[i], strerror(errno));
			return (false);
		}
		i++;
	}
	return (true);
}

bool	open_outfile_if_needed(t_cmd *cmd, int *fd)
{
	size_t	i;

	if (!cmd || !fd)
		return (false);
	i = 0;
	while (cmd->outfile[i])
	{
		if (*fd >= 0)
			close(*fd);
		if (ambiguous_redirect(cmd->outfile[i]))
			return (false);
		if (cmd->append)
			*fd = open(cmd->outfile[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			*fd = open(cmd->outfile[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*fd < 0)
		{
			ft_eprintf("minishell: %s: %s\n", cmd->outfile[i], strerror(errno));
			return (false);
		}
		i++;
	}
	return (true);
}
