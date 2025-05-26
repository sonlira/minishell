/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:48:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 14:35:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_sn(t_fmtbuf *fmt, int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_sn(fmt, '-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_sn(fmt, (num / 10));
	ft_putchar_sn(fmt, (num % 10 + '0'));
}

static void	args_format_sn(t_fmtbuf *fmt, const char format, va_list args)
{
	if (format == 'c')
		ft_putchar_sn(fmt, va_arg(args, int));
	else if (format == 's')
		ft_putstr_sn(fmt, va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		ft_putnbr_sn(fmt, va_arg(args, int));
	else if (format == 'u')
		ft_putunbr_sn(fmt, va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ft_puthex_sn(fmt, va_arg(args, unsigned int), format);
	else if (format == 'p')
		ft_putptr_sn(fmt, va_arg(args, void *));
	else if (format == '%')
		ft_putchar_sn(fmt, '%');
}

static void	init_fmtbuf(t_fmtbuf *fmt, char *buf, size_t size)
{
	fmt->buf = buf;
	fmt->size = size;
	fmt->it = 0;
	fmt->len = 0;
}

static void	null_terminate(t_fmtbuf *fmt)
{
	if (fmt->it < fmt->size)
		fmt->buf[fmt->it] = 0;
	else if (fmt->size > 0)
		fmt->buf[fmt->size - 1] = 0;
}

int	ft_snprintf(char *buf, size_t size, const char *format, ...)
{
	va_list		args;
	size_t		i;
	t_fmtbuf	fmt;

	va_start(args, format);
	i = 0;
	init_fmtbuf(&fmt, buf, size);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_sn(&fmt, format[i]);
		else
		{
			i++;
			if (format[i])
				args_format_sn(&fmt, format[i], args);
			else
				break ;
		}
		i++;
	}
	va_end(args);
	null_terminate(&fmt);
	return (fmt.len);
}
