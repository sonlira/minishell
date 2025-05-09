/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:07:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/09 17:06:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strchr_idx(const char *s, int c, size_t i) // Comprobar barras?
// {
// 	i++;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c && (s[i - 1] || i == 0))
// 		{
// 			if (i == 0)
// 				return (i);
// 			else if (s[i - 1] && s[i - 1] != '\\')
// 				return (i);
// 		}
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return (i);
// 	return (i - 1);
// }

bool	ft_strchr_idx(const char *s, int c, size_t *idx) // Comprobar barras?
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
