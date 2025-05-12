/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:14:34 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 19:23:28 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Reemplaza el contenido de *dest por una copia de src.
 * Si falla la asignación, *dest no se modifica.
 * Devuelve true si tuvo éxito, false si falló.
 */
bool	ft_set_string(char **dest, const char *src)
{
	char	*s;

	if (!dest || !src)
		return (false);
	s = ft_strdup(src);
	if (!s)
		return (false);
	if (*dest)
		free(*dest);
	*dest = s;
	return (true);
}
