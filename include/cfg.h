/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:06:55 by jaju              #+#    #+#             */
/*   Updated: 2023/09/08 13:55:17 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H

# include <stdbool.h>
# include <stdint.h>
# include <libds.h>

typedef struct s_token	t_token;

typedef struct s_token
{
	const char	*type;
	char		*lexeme;
}t_token;

typedef struct s_scanner
{
	char	*str;
	t_token	look_ahead;
	int32_t	cursor;
}t_scanner;

typedef struct s_parser
{
	
}

void	scanner_init(t_scanner *this, const char *str);
bool	scanner_has_next(t_scanner *this);
t_token	*scanner_peek(const t_scanner *this);
t_token	*scanner_next(t_scanner *this);

#endif
