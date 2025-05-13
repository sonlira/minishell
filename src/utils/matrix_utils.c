/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:02:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 21:01:56 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	matrix_push(char ***matrix, const char *value)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**new_matrix;

	if (!matrix || !value)
		return (false);
	size = ft_count_elements((const char **)*matrix);
	new_matrix = ft_calloc((size + 2), sizeof(char *));
	if (!new_matrix)
		return (false);
	i = 0;
	j = 0;
	while ((*matrix)[i])
	{
		new_matrix[j] = ft_strdup((*matrix)[i++]);
		if (!new_matrix[j++])
			return (ft_free_split(&new_matrix), false);
	}
	new_matrix[j] = ft_strdup(value);
	if (!new_matrix[j])
		return (ft_free_split(&new_matrix), false);
	ft_free_split(matrix);
	*matrix = new_matrix;
	return (true);
}

bool	matrix_unshift(char ***matrix, const char *value)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**new_matrix;

	if (!matrix || !value)
		return (false);
	size = ft_count_elements((const char **)*matrix);
	new_matrix = ft_calloc((size + 2), sizeof(char *));
	if (!new_matrix)
		return (false);
	new_matrix[0] = ft_strdup(value);
	if (!new_matrix[0])
		return (ft_free_split(&new_matrix), false);
	i = 0;
	j = 1;
	while ((*matrix)[i])
	{
		new_matrix[j] = ft_strdup((*matrix)[i++]);
		if (!new_matrix[j++])
			return (ft_free_split(&new_matrix), false);
	}
	ft_free_split(matrix);
	*matrix = new_matrix;
	return (true);
}
