/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:45:18 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/29 12:22:58 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	warn_heredoc_eof(t_cmd *cmd)
{
	ft_eprintf("minishell: warning: the document is delimited ");
	ft_eprintf("by end-of-file (expected «%s»)\n", cmd->delimiter);
}

static void	write_heredoc_line(t_cmd *cmd, t_shell *sh, int pips[2], char *line)
{
	char	*str;

	str = ft_strdup(line);
	if (!str)
		return ;
	if (!cmd->is_quoted)
		expander_dollar_args(sh, &str, true);
	write(pips[1], str, ft_strlen(str));
	write(pips[1], "\n", ft_strlen("\n"));
	free(str);
	free(line);
}

bool	handle_heredoc(t_shell *shell, t_cmd *cmd, int *fd_read)
{
	int		pipes[2];
	char	*line;

	if (!cmd || !fd_read)
		return (false);
	if (pipe(pipes) == -1)
		return (false);
	while (1)
	{
		setup_signals();
		line = readline("> ");
		if (g_signal == SIGINT)
			return (sigint_heredoc(pipes, line));
		if (!line)
		{
			warn_heredoc_eof(cmd);
			break ;
		}
		if (!ft_strcmp(line, cmd->delimiter))
			break ;
		write_heredoc_line(cmd, shell, pipes, line);
	}
	close(pipes[1]);
	*fd_read = pipes[0];
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
