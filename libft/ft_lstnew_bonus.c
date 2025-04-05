/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:42:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/01/21 16:23:06 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if(!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return(new_node);
}

// int main()
// {
// 	//t_list *cabeza;
// 	//cabeza = NULL;
// 	t_list	*nodo;
// 	char	*hola = "hola";

// 	nodo = ft_lstnew(hola);
// 	printf("%s", (char *)nodo->content);
// 	return 0;
// }