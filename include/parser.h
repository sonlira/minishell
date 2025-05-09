/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:43:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/05/09 20:06:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char	**ft_split_parse(char const *s, char c);
int		parser(t_shell *shell, char *line);
bool		count_valid_pipes(const char *s, size_t *pipes);
int		are_valid_quotes(const char *s);
bool	div_line(const char *s, char ***matrix);

#endif