/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:14:34 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/06 22:27:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchr_idx(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return (len);
	while (len--)
	{
		if (s[len] == (char)c)
			return (len);
	}
	return (-1);
}
