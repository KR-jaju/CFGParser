/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cfg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:06:55 by jaju              #+#    #+#             */
/*   Updated: 2023/09/04 15:49:35 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFG_H
# define CFG_H


typedef struct s_parser	t_parser;

typedef struct s_parser
{
	t_cfg	grammar;
}t_parser;

void	parser_init(t_parser *this, const char *str);
t_node	*parser_parse(t_parser *this);

#endif
