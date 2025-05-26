/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:29:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 19:31:41 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(int ***matrix, size_t size)
{
	size_t	i;

	if (!matrix || !*matrix || size < 1)
		return ;
	i = 0;
	while (i < size)
	{
		free((*matrix)[i]);
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

bool	create_matrix(int ***matrix, size_t rows, size_t cols)
{
	size_t	i;

	if (!matrix || *matrix || rows < 1 || cols < 1)
		return (false);
	*matrix = ft_calloc(rows, sizeof(int *));
	if (!*matrix)
		return (false);
	i = 0;
	while (i < rows)
	{
		(*matrix)[i] = ft_calloc(cols, sizeof(int));
		if (!(*matrix)[i])
			return (free_matrix(matrix, i), false);
		i++;
	}
	return (true);
}
