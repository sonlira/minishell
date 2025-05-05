/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_valist_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:44:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:18:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	args_format(const char format, va_list args, int fd)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar_fd(va_arg(args, int), fd);
	else if (format == 's')
		len += ft_putstr_fd(va_arg(args, char *), fd);
	else if (format == 'd' || format == 'i')
		len += ft_putnbr_fd(va_arg(args, int), fd);
	else if (format == 'u')
		len += ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (format == 'x' || format == 'X')
		len += ft_puthex_fd(va_arg(args, unsigned int), format, fd);
	else if (format == 'p')
		len += ft_putptr_fd(va_arg(args, void *), fd);
	else if (format == '%')
		len += ft_putchar_fd('%', fd);
	return (len);
}

int	ft_print_valist_fd(int fd, char const *str, va_list args)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar_fd(str[i], fd);
		else
		{
			i++;
			if (str[i])
				len += args_format(str[i], args, fd);
			else
				len += ft_putchar_fd('%', fd);
		}
		i++;
	}
	return (len);
}
