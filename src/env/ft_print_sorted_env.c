/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sorted_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:46:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/02 13:04:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

static void	sorted(char **env, size_t size)
{
	char	*aux;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				aux = env[i];
				env[i] = env[j];
				env[j] = aux;
			}
			j++;
		}
		i++;
	}
}

static void	print(char *str)
{
	char	**var;

	var = ft_split(str, '=');
	if (!var)
		return ;
	printf("declare -x %s", var[0]);
	if (var[1])
		printf("=\"%s\"", var[1]);
	printf("\n");
	ft_free_split(&var);
}

void	print_sorted_env(char **env)
{
	size_t	size;
	size_t	i;
	char	**matrix;

	if (!env)
		return ;
	matrix = copy_env((const char **)env);
	if (!matrix)
		return ;
	size = env_count((const char **)env);
	sorted(matrix, size);
	i = 0;
	while (matrix[i])
	{
		print(matrix[i]);
		i++;
	}
	free_env(&matrix);
}
