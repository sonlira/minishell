/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:34:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/19 14:09:08 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_llong_in_range(unsigned long long num, int sig)
{
	if (sig == 1 && num > LLONG_MAX)
		return (false);
	if (sig == -1 && num > (unsigned long long)LLONG_MAX + 1)
		return (false);
	return (true);
}

long long	ft_atoll(const char *str)
{
	unsigned long long		num;
	int						sig;
	size_t					i;

	num = 0;
	sig = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (!is_llong_in_range(num, sig))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return ((long long)num * sig);
}
