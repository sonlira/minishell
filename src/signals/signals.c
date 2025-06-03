/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:52:00 by abaldelo          #+#    #+#             */
/*   Updated: 2025/06/03 13:27:02 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_sigint(int sig)
{
	g_signal = sig; // Para qué?

	if (g_signal == 1) //hace falta?
		return ;
	printf("\nminishell> ");
	g_signal = 1;
	// printf("\n"); Estas cuatro líneas creo que hacen lo mismo que la anterior
	// rl_replace_line("", 1);
	// rl_on_new_line();
	// rl_redisplay();
}

void	setup_signals(void)
{
	signal(SIGINT, handler_sigint); //Ctrl-C
	signal(SIGQUIT, SIG_IGN);//para el Ctrl-\.
	//ctrl-D por sistema se interpreta como EOF y esto, en nuestro programa lo cierra :)
}
