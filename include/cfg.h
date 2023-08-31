/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:06:55 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 15:38:55 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H

# include <list.h>
# include <map.h>

typedef struct s_parser	t_parser;
typedef struct s_rule	t_rule;
typedef struct s_node	t_node;
typedef struct s_expr	t_expr;
typedef	unsigned int	t_uint;

typedef struct s_parser
{
	t_cfg	grammar;
}t_parser;

typedef struct s_cfg
{
	t_entry	*entry;
}t_cfg;

typedef struct s_entry
{
	char	*identifier;
	char	**rule;
	t_entry	*next;
}t_entry;

typedef struct s_node
{
	const char	*identifier;
	const char	*str;
}t_node;

void	parser_init(t_parser *this, const char *str);
t_node	*parser_parse(t_parser *this);

#endif
