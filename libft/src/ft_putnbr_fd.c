/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:25:08 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:16:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	int			len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr_fd(n / 10, fd);
	len += ft_putchar_fd((n % 10 + '0'), fd);
	return (len);
}
