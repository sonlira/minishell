/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:02:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/22 21:33:11 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	get_path_dirs(char *const *envp, char ***array)
{
	char	*path;

	path = get_env_value(envp, "PATH");
	if (!path)
		return (false);
	*array = ft_split(path, ':');
	if (!*array)
		return (free(path), false);
	free(path);
	return (true);
}

int	ft_execvp(const char *cmd, char *const *args, char *const *envp)
{
	char	full_path[BUFF_SIZE];
	char	**dir;
	size_t	i;

	i = 0;
	if (ft_strchr(cmd, '/'))
		execve(cmd, args, envp);
	if (!get_path_dirs(envp, &dir))
		return (errno = ENOENT, ERROR);
	while (dir[i])
	{
		ft_snprintf(full_path, sizeof(full_path), "%s/%s", dir[i], cmd);
		if (!access(full_path, X_OK))
			execve(full_path, args, envp);
		i++;
	}
	errno = ENOENT;
	return (ft_free_split(dir), ERROR);
}

// ft_eprintf("minishell: %s: %s\n", cmd, strerror(errno));
