/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:35:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 20:35:29 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void	setup_shell_signals(void);
void	setup_exec_signals(void);
void	ignore_child_signals(void);
void	handler_sigint(int sig);
void	handler_eof(t_shell *shell, char *line);
bool	sigint_heredoc(int pipes[2], char *line);

#endif