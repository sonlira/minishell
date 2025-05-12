/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:21:54 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 12:23:58 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_elements(const char **matrix)
{
	int	count;

	count = 0;
	if (!matrix)
		return (count);
	while (matrix[count])
		count++;
	return (count);
}
