/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:02:30 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/30 19:33:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	array_push(char ***array, const char *value)
{
	t_iterator	it;
	size_t		size;
	char		**new_array;

	if (!array || !value)
		return (false);
	size = ft_count_elements((const char **)*array);
	new_array = ft_calloc((size + 2), sizeof(char *));
	if (!new_array)
		return (false);
	init_iterator(&it);
	while (size != 0 && (*array)[it.i])
	{
		new_array[it.j] = ft_strdup((*array)[it.i++]);
		if (!new_array[it.j++])
			return (ft_free_split(&new_array), false);
	}
	new_array[it.j] = ft_strdup(value);
	if (!new_array[it.j])
		return (ft_free_split(&new_array), false);
	ft_free_split(array);
	*array = new_array;
	return (true);
}

bool	array_unshift(char ***array, const char *value)
{
	t_iterator	it;
	size_t		size;
	char		**new_array;

	if (!array || !value)
		return (false);
	size = ft_count_elements((const char **)*array);
	new_array = ft_calloc((size + 2), sizeof(char *));
	if (!new_array)
		return (false);
	init_iterator(&it);
	new_array[it.j] = ft_strdup(value);
	if (!new_array[it.j++])
		return (ft_free_split(&new_array), false);
	while (size != 0 && (*array)[it.i])
	{
		new_array[it.j] = ft_strdup((*array)[it.i++]);
		if (!new_array[it.j++])
			return (ft_free_split(&new_array), false);
	}
	ft_free_split(array);
	*array = new_array;
	return (true);
}

bool	dup_str_array_into(char ***dst, char **orig)
{
	size_t	i;
	size_t	size;

	if (!dst ||!orig || !*orig)
		return (false);
	if (*dst)
		ft_free_split(dst);
	size = ft_count_elements((const char **)orig);
	*dst = ft_calloc((size + 1), sizeof(char *));
	if (!*dst)
		return (false);
	i = 0;
	while (orig[i])
	{
		(*dst)[i] = ft_strdup(orig[i]);
		if (!(*dst)[i])
			return (ft_free_split(dst), false);
		i++;
	}
	return (true);
}
