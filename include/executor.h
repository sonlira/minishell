/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 15:07:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

void	execute_shell_command(t_shell *shell);
int		ft_execvp(const char *cmd, char *const *args, char *const *envp);
bool	init_pipes(int ***pipes, size_t size);
void	close_pipes(int **pipes, size_t size);
void	destroy_pipes(int ***pipes, size_t size);
bool	process_heredocs(t_shell *shell, t_cmd *cmd);
bool	init_forks(t_shell *shell, t_cmd *cmd, \
		void (*child_fn)(t_shell *, t_cmd *, size_t idx));
void	wait_and_free_forks(pid_t **pids, size_t size, int *status);
bool	open_infile_if_needed(t_cmd *cmd, int *fd);
bool	open_outfile_if_needed(t_cmd *cmd, int *fd);
bool	handle_heredoc(t_shell *shell, t_cmd *cmd, int pipes[2]);
void	execute_simple_cmd(t_shell *shell, t_cmd *cmd);
void	execute_piped_cmd(t_shell *shell, t_cmd *cmd, int **pipes, size_t idx);

#endif