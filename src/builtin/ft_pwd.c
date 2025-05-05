/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:12:29 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 11:44:55 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0); //NULL, 0 hace que se reserve memoria del tamaño que necesito. 
	if (!cwd)
		return (EXIT_KO);
	printf("%s\n", cwd);
	free(cwd);
	return (EXIT_OK);
}
