/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/15 12:43:58 by bgil-fer         ###   ########.fr       */
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

void	check_redirection(t_cmd *cmd, char **split, size_t i)
{
	if (!ft_strcmp(split[i], "<<") && split[i + 1])
	{
		cmd->heredoc = true;
		cmd->delimiter = ft_strdup(split[i + 1]);
		if (cmd->delimiter[0] == 34 || cmd->delimiter[0] == 39)
			cmd->quoted = true;
	}
	else if (!ft_strcmp(split[i], ">>") && split[i + 1])
		cmd->append = 1;
	else if (!ft_strcmp(split[i], "<") && split[i + 1])
		ft_set_string(&cmd->infile, split[i]);
	else if (!ft_strcmp(split[i], ">") && split[i + 1])
		matrix_unshift(&cmd->outfile, split[i]);
}

bool	fill_cmd(t_cmd *cmd, char **split)
{
	size_t	i;
	char	**args;
	t_cmd	*tmp;

	if (!split)
		return (false);
	i = 0;
	while (split[i])
	{
		if (is_empty_quote(split[i]))
			i++;
		check_redirection(cmd, split, i);
		if (!ft_strcmp(split[i], "|"))
		{
			cmd->next = create_cmd_struct();
			cmd->cmd = ft_strdup(args[0]);
			tmp = cmd->next;
			fill_cmd(tmp, split + i); //revisar
		}
		else
			matrix_push(&args, split[i]);
		i++;
	}
	cmd->cmd = ft_strdup(args[0]);
	return (true);
}

bool	fill_t_shell(t_shell *shell, char **matrix) // cambiar el nombre y tambien esta en proceso
{
	char	**split;
	size_t	i;

	if (!shell->cmd_list)
		return (false);
	if (!create_cmd_array(shell, ft_count_elements((const char **)matrix)))
		return (false);
	i = 0;
	while (matrix[i])
	{
		if (!split_ignoring_quotes(matrix[i], &split))
			return (ft_free_split(&matrix), false);
		if (!fill_cmd(shell->cmd_list[i], split))
			return (false);
		i++;
	}
	return (true);
}

bool	parse_input(t_shell *shell, const char *input) //falta comprobar redirecciones
{
	char	*input_format;
	char	**matrix;

	if (!shell || !input)
		return (false);
	if (!are_valid_quotes(input))
		return (false);
	if (!are_valid_semicolon(input) || !are_valid_pipes(input))
		return (false);
	input_format = format_prompt_str(input);
	if (!input_format)
		return (false);
	if (split_valid_semicolons(input_format, &matrix))
	{
		fill_t_shell(shell, matrix);
	}
	free(input_format);
	ft_free_split(&matrix);
	return (true);
}
