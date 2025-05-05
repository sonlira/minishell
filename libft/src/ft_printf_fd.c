/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:23:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 21:22:16 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(int fd, char const *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = ft_print_valist_fd(fd, str, args);
	va_end(args);
	return (len);
}
