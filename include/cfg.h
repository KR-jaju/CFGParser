/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:06:55 by jaju              #+#    #+#             */
/*   Updated: 2023/09/09 16:01:55 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H

# include <stdbool.h>
# include <stdint.h>
# include <libds.h>


typedef enum e_token_type
{
	TK_TERMINAL,
	TK_KEYWORD,
	TK_NUMBER,
	TK_VEC3
}t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*lexeme;
	struct s_token	*children;
	size_t			count;
}t_token;

typedef struct s_scanner
{
	char	*str;
	t_token	look_ahead;
	int32_t	cursor;
}t_scanner;

void	scanner_init(t_scanner *this, const char *str);
bool	scanner_has_next(t_scanner *this);
t_token	*scanner_peek(const t_scanner *this);
t_token	*scanner_next(t_scanner *this);

#endif
