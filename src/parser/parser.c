/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/25 20:13:57 by abaldelo         ###   ########.fr       */
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
static void	expand_and_prepare(t_shell *sh, t_cmd *cmd, char **split, size_t *i)
{
	size_t	size;

	if (!ft_strcmp(split[*i], "<<"))
	{
		// expander_dollar_args(sh, &split[++(*i)], true); No hace falta expadir $VAR en delimitadores
		(*i)++;
		size = ft_count_elements((const char **)cmd->delimiter);
		if (ft_is_rawchar(split[*i], 34) || ft_is_rawchar(split[*i], 39))
			bool_array_push(&cmd->is_quoted, true, size);
		else
			bool_array_push(&cmd->is_quoted, false, size);
		remove_quotes_and_backslashes(sh, &split[*i]);
		array_push(&cmd->delimiter, split[*i]);
	}
	else if (!ft_strcmp(split[*i], ">>") || !ft_strcmp(split[*i], ">"))
		process_redir_target(sh, cmd, &split[++(*i)], ">");
	else if (!ft_strcmp(split[*i], "<"))
		process_redir_target(sh, cmd, &split[++(*i)], "<");
}

static bool	check_redirection(t_shell *sh, t_cmd *cmd, char **split, size_t *i)
{
	if (!ft_strcmp(split[*i], "<<"))
	{
		cmd->last_redir = REDIR_HEREDOC;
		cmd->heredoc = true;
		expand_and_prepare(sh, cmd, split, i);
		return (true);
	}
	else if (!ft_strcmp(split[*i], ">>") || !ft_strcmp(split[*i], ">"))
	{
		if (!ft_strcmp(split[*i], ">>"))
			cmd->append = true;
		expand_and_prepare(sh, cmd, split, i);
		return (true);
	}
	else if (!ft_strcmp(split[*i], "<"))
	{
		cmd->last_redir = REDIR_INFILE;
		expand_and_prepare(sh, cmd, split, i);
		return (true);
	}
	return (false);
}

static bool	fill_cmd(t_shell *shell, t_cmd *cmd, char **split, size_t *i)
{
	while (split[*i])
	{
		if (check_redirection(shell, cmd, split, i))
			(*i)++;
		else if (!ft_strcmp(split[*i], "|"))
		{
			validate_and_parse_cmd(cmd);
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
			process_cmd_arg(shell, cmd, &split[*i]);
			ft_set_string(&shell->last_arg, split[*i]);
			(*i)++;
		}
	}
	return (validate_and_parse_cmd(cmd));
}

static bool	fill_t_shell(t_shell *shell, char **matrix)
{
	char	**args;
	size_t	i;
	size_t	j;

	if (!create_cmd_list(shell, ft_count_elements((const char **)matrix)))
		return (false);
	i = 0;
	while (matrix[i])
	{
		j = 0;
		(void)j;
		if (!split_ignoring_quotes(shell, matrix[i], &args))
			return (ft_free_split(&matrix), false);
		// ft_print_str_array(args); // imprimir argumentos
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
	set_env_var(&shell->env_cpy, "_", shell->last_arg);
	return (true);
}
