/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:12:44 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:17:02 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	while (s[len])
		len += ft_putchar_fd(*s, fd);
	return (len);
}
