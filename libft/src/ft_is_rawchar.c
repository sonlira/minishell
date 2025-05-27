/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_rawchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:48:10 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/27 11:23:46 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_rawchar(const char *s, int c)
{
	return (ft_find_rawchar(s, c, &(size_t){0}));
}
