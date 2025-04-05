/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:13:46 by abaldelo          #+#    #+#             */
/*   Updated: 2025/01/21 17:23:56 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while(lst)
	{
		if(!(lst->next))
			break;
		lst = lst->next;
	}
	return(lst);
}

// int main()
// {
// 	t_list *cabeza = NULL;
// 	t_list *uno;
// 	t_list	*tmp;
// 	t_list *dos;
// 	t_list *tres;
// 	char *str = "Hola1";
// 	char *str2 = "Hola2";
// 	char *str3 = "Hola3";
// 	uno = ft_lstnew(str);
// 	if (!uno)
// 		return (1);
// 	dos = ft_lstnew(str2);
// 	if (!dos)
// 		return (1);
// 	tres = ft_lstnew(str3);
// 	if (!tres)
// 		return (1);
// 	tmp = cabeza;
// 	tmp = uno;
// 	uno->next = dos;
// 	dos->next = tres;
// 	printf("contenido de ulimo nodo: %s",(char *)ft_lstlast(tmp)->content);
// 	return 0;
// }