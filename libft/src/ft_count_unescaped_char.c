/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unescaped_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:55:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/06 21:25:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_unescaped_char(const char *s, int c)
{
	if (!s)
		return (0);
	return (ft_count_char(s, c) - ft_count_escaped_char(s, c));
}
