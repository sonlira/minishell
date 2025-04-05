/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:09:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/01/21 16:22:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && lst)
		new->next = (*lst);
	(*lst) = new;
}

// int main()
// {
// 	t_list *cabeza = NULL;
// 	t_list *uno;
// 	t_list	*tmp;
// 	t_list *dos;
// 	t_list *tres;
// 	char *str = "Hola";
// 	char *str2 = "Hola2";
// 	char *str3 = "Hola3";
// 	uno = ft_lstnew(str);
// 	if (!uno)
// 		return (1);
// 	ft_lstadd_front(&cabeza, uno);
// 	dos = ft_lstnew(str2);
// 	if (!dos)
// 		return (1);
// 	ft_lstadd_front(&cabeza, dos);
// 	tres = ft_lstnew(str3);
// 	if (!tres)
// 		return (1);
// 	ft_lstadd_front(&cabeza, tres);
// 	tmp = cabeza;
// 	while (tmp)
// 	{
// 		printf("%s",(char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return 0;
// }