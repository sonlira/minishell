/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_rawchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:07:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/12 17:31:25 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_find_rawchar(const char *s, int c, size_t *idx)
{
	size_t	i;

	i = *idx + 1;
	while (s[i])
	{
		if (s[i] == (char)c && s[i - 1] != 92)
		{
			*idx = i;
			return (true);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		*idx = i;
		return (true);
	}
	return (false);
}
