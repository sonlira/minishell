/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:20:37 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 20:17:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(void *p, int fd)
{
	int					len;
	unsigned long long	pnum;

	len = 0;
	pnum = (unsigned long long)p;
	if (!pnum)
		len += ft_putstr_fd("(nil)", fd);
	else
	{
		len += ft_putstr_fd("0x", fd);
		len += ft_puthex_fd(pnum, 'x', fd);
	}
	return (len);
}
