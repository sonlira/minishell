/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:39:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/28 23:03:29 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "includes.h"
# include "enums.h"
# include "types.h"
# include "parser.h"
# include "executor.h"
# include "env.h"
# include "utils.h"
# include "builtin.h"
# include "signals.h"

extern volatile sig_atomic_t	g_signal;

#endif