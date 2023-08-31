/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:06:19 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 02:13:53 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

int		str_length(char const *str);
char	*str_substr(char const *str, int start, int end);
int		str_includes(char const *str, char c);
char	*str_tokenize(char *str, char const *delim, char **saved);
char	*str_replace(char const *str, char const *replaced, char *with);
int		str_equals(char const *a, char const *b);
char	*str_join(char const *a, char const *b);
int		str_indexof(char const *str, char c);
char	*str_clone(char const *str);

#endif