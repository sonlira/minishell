/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:42:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 14:09:40 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	initialize_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->append = 0;
	cmd->heredoc = 0;
	cmd->next = NULL;
}

void	parse(t_cmd *cmd, char *line)
{
	size_t	i;

	cmd->args = ft_split_parse(line, ' ');
	cmd->cmd = cmd->args[0];
	i = 0;
	while (cmd->args[i])
	{
		if (!ft_strcmp(cmd->args[i], "<<") && cmd->args[i + 1])
			cmd->heredoc = 1;
		else if (!ft_strcmp(cmd->args[i], ">>") && cmd->args[i + 1])
			cmd->append = 1;
		else if (!ft_strcmp(cmd->args[i], "<") && cmd->args[i + 1])
			cmd->infile = ft_strdup(cmd->args[i + 1]);
		else if (!ft_strcmp(cmd->args[i], ">") && cmd->args[i + 1])
			cmd->outfile = ft_strdup(cmd->args[i + 1]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_cmd	cmd;
	size_t	i;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
			break ; // Ctrl+D
		add_history(line);
		// aquí va el parsing y ejecución
		initialize_cmd(&cmd);
		parse(&cmd, line);
		i = 0;
		while (cmd.args[i])
		{
			printf("args[%zd] %s\n", i, cmd.args[i]);
			i++;
		}
		printf("heredoc = %i\nappend = %i\ninfile = %s\noutfile = %s\n", cmd.heredoc, cmd.append, cmd.infile, cmd.outfile);
		free(line);
	}
	return (0);
}
