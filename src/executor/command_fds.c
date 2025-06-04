/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:45:18 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/06/04 20:28:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	warn_heredoc_eof(char *delimiter)
{
	ft_eprintf("minishell: warning: the document is delimited ");
	ft_eprintf("by end-of-file (expected «%s»)\n", delimiter);
}

static void	write_heredoc_line(bool is_quoted, t_shell *sh, int fd, char *line)
{
	char	*str;

	str = ft_strdup(line);
	if (!str)
		return ;
	if (!is_quoted)
		expander_dollar_args(sh, &str, true);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", ft_strlen("\n"));
	free(str);
	free(line);
}

bool	handle_heredoc(t_shell *shell, t_cmd *cmd, int pipes[2])
{
	char	*line;
	size_t	i;

	close(pipes[0]);
	if (!cmd || pipes[1] < 0)
		return (false);
	i = 0;
	while (cmd->delimiter[i])
	{
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				warn_heredoc_eof(cmd->delimiter[i]);
				break ;
			}
			if (!ft_strcmp(line, cmd->delimiter[i]))
				break ;
			write_heredoc_line(cmd->is_quoted[i], shell, pipes[1], line);
		}
		i++;
	}
	return (free(line), true);
}

bool	open_infile_if_needed(t_cmd *cmd, int *fd)
{
	if (!cmd || !fd)
		return (false);
	*fd = open(cmd->infile, O_RDONLY);
	if (*fd < 0)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->infile, strerror(errno));
		return (false);
	}
	return (true);
}

bool	open_outfile_if_needed(t_cmd *cmd, int *fd)
{
	size_t	i;
	int		ignore_fd;

	if (!cmd || !fd)
		return (false);
	i = 0;
	if (cmd->append)
		*fd = open(cmd->outfile[i++], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*fd = open(cmd->outfile[i++], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
	{
		ft_eprintf("minishell: %s: %s\n", cmd->outfile, strerror(errno));
		return (false);
	}
	while (cmd->outfile[i])
	{
		ignore_fd = open(cmd->outfile[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ignore_fd >= 0)
			close(ignore_fd);
		i++;
	}
	return (true);
}
