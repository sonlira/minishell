/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:37:26 by abaldelo          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while(lst)
	{
		size++;
		lst = lst->next;
	}
	return(size);
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
// 	printf("numero de elementos: %d",ft_lstsize(tmp));
// 	return 0;
// }