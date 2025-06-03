/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:14:38 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 21:32:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// bool	sigint_heredoc(int pipes[2], char *line)
// {
// 	if (!line || !pipes)
// 		return (false);
// 	if (pipes[0] >= 0)
// 		close(pipes[0]);
// 	if (pipes[1] >= 1)
// 		close(pipes[1]);
// 	free(line);
// 	return (false);
// }
