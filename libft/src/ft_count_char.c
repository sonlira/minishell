/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:36:28 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/05/05 12:51:23 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
