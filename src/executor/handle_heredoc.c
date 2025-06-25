/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:10:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 19:29:11 by abaldelo         ###   ########.fr       */
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
