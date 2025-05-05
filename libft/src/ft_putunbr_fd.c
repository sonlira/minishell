/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:54:29 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:17:05 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunbr_fd((n / 10), fd);
	}
	len += ft_putchar_fd((n % 10 + '0'), fd);
	return (len);
}
