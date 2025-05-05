/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:03:03 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/05 21:19:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_std
{
	STDIN	= 0,
	STDOUT	= 1,
	STDERR	= 2
}	t_std;
typedef enum e_status
{
	ERROR	= -1,
	FAILURE = 0,
	SUCCESS = 1
}	t_status;

typedef enum e_builtin_status
{
	LIMITER	= 256,
	EXIT_OK	= 0,
	EXIT_KO	= 1,
	INVALID	= 2,
	UNKNOWN_COMMAND = 127,
}	t_builtin_status;

#endif
