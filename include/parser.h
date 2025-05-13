/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/13 22:59:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

bool	parser_input(t_shell *shell, const char *line);
bool	are_valid_delimiters(const char *s, int delimiter, size_t *total);
bool	are_valid_pipes(const char *s);
bool	are_valid_semicolon(const char *s);
bool	are_valid_quotes(const char *s);
bool	is_empty_quote(const char *str);
bool	split_ignore_quotes(char const *s, char ***matrix);
bool	count_valid_semicolon(const char *s, size_t *size);
bool	split_valid_semicolons(const char *s, char ***matrix);
char	*format_prompt_str(const char *s);

#endif