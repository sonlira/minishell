/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:28 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/05 21:15:31 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_char(const char *str, int c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!str || !c)
		return (count);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
