/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:39:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/22 22:53:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "includes.h"
# include "types.h"
# include "enums.h"
# include "parser.h"
# include "executor.h"
# include "env.h"
# include "utils.h"
# include "builtin.h"
# include "signals.h"

extern volatile sig_atomic_t	g_signal;

#endif