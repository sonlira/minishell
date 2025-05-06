/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_escaped_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:48:10 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/06 21:24:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_escaped_char(const char *s, int c)
{
	size_t	i;
	int		count;

	count = 0;
	if (!s)
		return (count);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1] == (char)c)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}
