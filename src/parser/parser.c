/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/02 23:45:55 by abaldelo         ###   ########.fr       */
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
static void	expand_and_clean(t_shell *sh, t_cmd *cmd, char ***args, size_t idx)
{
	expander_dollar_args(sh, &(*args)[idx], true);
	if (!ft_strcmp((*args)[idx], "<<"))
	{
		if (ft_is_rawchar((*args)[idx + 1], 34))
			cmd->is_quoted = true;
		else if (ft_is_rawchar((*args)[idx + 1], 39))
			cmd->is_quoted = true;
	}
	remove_quotes_and_backslashes(sh, &(*args)[idx]);
}

static bool	check_redirection(t_cmd *cmd, char **split, size_t *i)
{
	if (!ft_strcmp(split[*i], "<<"))
	{
		cmd->last_redir = REDIR_HEREDOC;
		cmd->heredoc = true;
		ft_set_string(&cmd->delimiter, split[++(*i)]);
		return (true);
	}
	else if (!ft_strcmp(split[*i], ">>") || !ft_strcmp(split[*i], ">"))
	{
		if (!ft_strcmp(split[*i], ">>"))
			cmd->append = true;
		array_unshift(&cmd->outfile, split[++(*i)]);
		return (true);
	}
	else if (!ft_strcmp(split[*i], "<"))
	{
		cmd->last_redir = REDIR_INFILE;
		ft_set_string(&cmd->infile, split[++(*i)]);
		return (true);
	}
	return (false);
}

static bool	fill_cmd(t_shell *shell, t_cmd *cmd, char **split, size_t *i)
{
	if (!split || !cmd)
		return (false);
	while (split[*i])
	{
		if (check_redirection(cmd, split, i))
			(*i)++;
		else if (!ft_strcmp(split[*i], "|"))
		{
			ft_set_string(&cmd->cmd, cmd->args[0]);
			cmd->next = create_cmd_struct();
			if (!cmd->next)
				return (false);
			cmd->next->prev = cmd;
			++(*i);
			if (!fill_cmd(shell, cmd->next, split, i))
				return (false);
		}
		else
		{
			expand_and_clean(shell, cmd, &split, *i);
			array_push(&cmd->args, split[*i]);
			(*i)++;
		}
	}
	return (ft_set_string(&cmd->cmd, cmd->args[0]));
}

static bool	fill_t_shell(t_shell *shell, char **matrix)
{
	char	**args;
	size_t	i;
	size_t	j;

	if (!shell || !matrix)
		return (false);
	if (!create_cmd_list(shell, ft_count_elements((const char **)matrix)))
		return (false);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		(void)j;
		if (!split_ignoring_quotes(shell, matrix[i], &args))
			return (ft_free_split(&matrix), false);
		if (!fill_cmd(shell, shell->cmd_list[i], args, &j))
			return (false);
		i++;
	}
	ft_free_split(&args);
	return (true);
}

bool	parse_input(t_shell *shell, const char *input)
{
	char	*input_format;
	char	**matrix;

	input_format = NULL;
	if (!shell || !input)
		return (false);
	if (!has_non_whitespace(input))
		return (false);
	if (!are_valid_quotes(shell, input))
		return (false);
	if (!are_valid_semicolon(shell, input) || !are_valid_pipes(shell, input))
		return (false);
	if (!format_prompt_str(shell, &input_format, input))
		return (false);
	if (!are_valid_redirection(shell, input_format))
		return (false);
	if (split_valid_semicolons(shell, input_format, &matrix))
	{
		if (!fill_t_shell(shell, matrix))
			return (free(input_format), ft_free_split(&matrix), false);
	}
	free(input_format);
	ft_free_split(&matrix);
	return (true);
}
