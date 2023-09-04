/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:06:55 by jaju              #+#    #+#             */
/*   Updated: 2023/09/05 00:30:35 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H


typedef struct s_parser	t_parser;

typedef struct s_parser
{
	t_cfg	grammar;
}t_parser;

typedef struct s_node
{
	char	c;
	t_node	*children;
}t_node;

void	parser_init(t_parser *this, const char *str);
t_node	*parser_parse(t_parser *this);

#endif
