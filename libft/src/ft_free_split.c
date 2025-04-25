/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-25 19:51:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025-04-25 19:51:03 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char ***matriz)
{
	size_t	i;

	if (!matriz || !*matriz)
		return ;
	i = 0;
	while ((*matriz)[i])
	{
		free((*matriz)[i]);
		i++;
	}
	free(*matriz);
	*matriz = NULL;
}
