/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:37:18 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 14:58:08 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_printf_error(char const *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	len = ft_print_valist_fd(STDERR_FILENO, str, args);
	va_end(args);
	return (len);
}
