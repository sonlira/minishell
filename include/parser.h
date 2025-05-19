/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/19 20:01:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

bool	parse_input(t_shell *shell, const char *line);
bool	are_valid_delims(t_shell *sh, const char *s, int delim, size_t *total);
bool	are_valid_pipes(t_shell *shell, const char *s);
bool	are_valid_semicolon(t_shell *shell, const char *s);
bool	are_valid_quotes(t_shell *shell, const char *s);
bool	are_valid_redirection(t_shell *shell, const char *str);
bool	split_ignoring_quotes(t_shell *shell, char const *s, char ***matrix);
bool	count_valid_semicolon(t_shell *shell, const char *s, size_t *size);
bool	split_valid_semicolons(t_shell *shell, const char *s, char ***matrix);
bool	format_prompt_str(t_shell *shell, char **d, const char *s);
bool	has_non_whitespace(const char *s);
bool	expander_dollar_args(t_shell *shell, char **s, bool expander_dquote);
bool	remove_quotes_and_backslashes(t_shell *shell, char **s);

#endif