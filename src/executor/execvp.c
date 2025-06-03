/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execvp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:02:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 18:11:50 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	get_path_dirs(char *const *envp, char ***array)
{
	char	*path;

	path = get_env_value((char **)envp, "PATH");
	if (!path || !*path)
		return (false);
	*array = ft_split(path, ':');
	if (!*array)
		return (free(path), false);
	free(path);
	return (true);
}

static bool	try_direct_exec(const char *cmd, char *const *args, char *const *ev)
{
	struct stat	st;

	if (!ft_strchr(cmd, '/'))
		return (true);
	if (execve(cmd, args, ev) == -1)
	{
		if (errno == EACCES && !stat(cmd, &st) && S_ISDIR(st.st_mode))
			errno = EISDIR;
		return (false);
	}
	return (true);
}

int	ft_execvp(const char *cmd, char *const *args, char *const *envp)
{
	char	full_path[BUFF_SIZE];
	char	**dir;
	size_t	i;

	i = 0;
	if (!try_direct_exec(cmd, args, envp))
		return (ERROR);
	if (!get_path_dirs(envp, &dir))
	{
		errno = ENOENT;
		ft_eprintf("minishell: %s: %s\n", cmd, strerror(errno));
		exit(UNKNOWN_COMMAND);
	}
	while (dir[i])
	{
		ft_snprintf(full_path, sizeof(full_path), "%s/%s", dir[i], cmd);
		if (!access(full_path, X_OK))
			execve(full_path, args, envp);
		i++;
	}
	ft_free_split(&dir);
	ft_eprintf("minishell: %s: command not found\n", cmd);
	exit(UNKNOWN_COMMAND);
}
