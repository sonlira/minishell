/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:52:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/18 15:24:02 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_eof(t_shell *shell, char *line)
{
	if (line)
		free(line);
	free_struct(shell);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	rl_clear_history();
	exit(shell->last_exit);
}

void	handler_sigint(int sig)
{
	(void)sig;
	if (!g_status)
		g_status = 130;
	ft_putstr_fd("\n", STDOUT_FILENO); //hacemos salto de linea para no tener minishell>^C minishell> en una sola linea
	rl_replace_line("", 1); // 1 Borra la linea sin guardar 0 guarda la linea (ejm. cat^C) <- con 0 se guarda en fichero para recuperar eso. Pero yo no lo quiero por eso uso 1. 
	rl_on_new_line(); // Nos movemos a la nueva linea
	rl_redisplay(); // vuelve a mostrar el prompt (minishell >)
}

void	setup_shell_signals(void)
{
	struct sigaction	sa; //estructura para poder trabajar con sigaction

	ft_bzero(&sa, sizeof(sa)); // Iniciamos los campos de sa a 0
	sa.sa_handler = handler_sigint; // funcion que se usara cuando se produzca la señal (SIGINT)
	sigaction(SIGINT, &sa, NULL); //
	signal(SIGQUIT, SIG_IGN);//para el Ctrl-\.
	//ctrl-D por sistema se interpreta como EOF y esto, en nuestro programa lo cierra :)
}

void	setup_exec_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

void	ignore_child_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
