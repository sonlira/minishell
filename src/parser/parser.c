/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 22:01:59 by abaldelo         ###   ########.fr       */
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
bool	llenar_cmd(t_cmd *cmd, char **split) // esto esta en proceso (no funciona)
{
	size_t	i;
	char	args[BUFF_SIZE];

	i = 0;
	while (split[i])
	{
		if (!ft_strcmp(split[i], "<<") && cmd->args[i + 1])
			cmd->heredoc = 1;
		else if (!ft_strcmp(split[i], ">>") && cmd->args[i + 1])
			cmd->append = 1;
		else if (!ft_strcmp(split[i], "<") && cmd->args[i + 1])
			cmd->infile = ft_strdup(cmd->args[i + 1]);
		else if (!ft_strcmp(cmd->args[i], ">") && cmd->args[i + 1])
			cmd->outfile = ft_strdup(cmd->args[i + 1]);
		i++;
	}
	return (true);
}

bool	prov(t_shell *shell, char **matrix) // cambiar el nombre y tambien esta en proceso
{
	char	**split;
	size_t	i;
	size_t	size;

	size = ft_count_elements((const char **)matrix);
	shell->cmd_list = ft_calloc((size + 1), sizeof(t_cmd));
	if (!shell->cmd_list)
		return (false);
	i = 0;
	while (matrix[i])
	{
		if (!split_ignore_quotes(matrix[i], &split))
			return (ft_free_split(&matrix), false);
		if (!llenar_cmd(&shell->cmd_list[i], split))
			return (false);
		i++;
	}
	return (true);
}

bool	parser_input(t_shell *shell, const char *input)
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
		prov(shell, matrix);
	}
	// else if (split_ignore_quotes(format_str, &matrix))
	// {
	// 	trabajamos aqui;
	// }
	free(input_format);
	ft_free_split(&matrix);
	return (true);
}
