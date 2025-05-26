/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/26 21:00:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

void	execute_shell_command(t_shell *shell);
int		ft_execvp(const char *cmd, char *const *args, char *const *envp);
bool	init_pipes(int ***pipes, size_t size);
void	close_pipes(int **pipes, size_t size);
void	destroy_pipes(int ***pipes, size_t size);
bool	init_forks(pid_t **pids, size_t size);
void	cleanup_forks(pid_t **pids, size_t size);

#endif