/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:16:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 14:22:15 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static	int	replace_char(int c)
{
	if (c == 'x')
		return ('a');
	if (c == 'X')
		return ('A');
	return (c);
}

int	ft_puthex_fd(unsigned long long n, char c, int fd)
{
	int	len;

	len = 0;
	c = replace_char(c);
	if (n >= 16)
	{
		len += ft_puthex_fd((n / 16), c, fd);
		len += ft_puthex_fd((n % 16), c, fd);
	}
	else
	{
		if (n >= 10)
			len += ft_putchar_fd((n - 10 + c), fd);
		else
			len += ft_putchar_fd((n + '0'), fd);
	}
	return (len);
}
