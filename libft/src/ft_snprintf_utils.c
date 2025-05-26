/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:32:34 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 14:33:37 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_sn(t_fmtbuf *fmt, unsigned int num)
{
	if (num >= 10)
		ft_putunbr_sn(fmt, (num / 10));
	ft_putchar_sn(fmt, (num % 10 + '0'));
}

void	ft_putptr_sn(t_fmtbuf *fmt, void *ptr)
{
	unsigned long long	num;

	num = (unsigned long long)ptr;
	if (!num)
		ft_putstr_sn(fmt, "(nil)");
	else
	{
		ft_putstr_sn(fmt, "0x");
		ft_puthex_sn(fmt, num, 'x');
	}
}

void	ft_puthex_sn(t_fmtbuf *fmt, unsigned long long num, char base)
{
	if (base == 'X')
		base = 'A';
	else if (base == 'x')
		base = 'a';
	if (num >= 16)
		ft_puthex_sn(fmt, (num / 16), base);
	if (num % 16 >= 10)
		ft_putchar_sn(fmt, (num % 16 - 10 + base));
	else
		ft_putchar_sn(fmt, (num % 16 + '0'));
}

void	ft_putchar_sn(t_fmtbuf *fmt, int c)
{
	if (fmt->it < fmt->size - 1)
		fmt->buf[fmt->it++] = (char)c;
	fmt->len++;
}

void	ft_putstr_sn(t_fmtbuf *fmt, char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] && fmt->it < fmt->size - 1)
		ft_putchar_sn(fmt, str[i++]);
}
