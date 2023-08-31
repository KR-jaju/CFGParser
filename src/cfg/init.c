/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:56:32 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 15:48:02 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfg.h>
#include <buffer.h>
#include <str.h>

static
void	entry_init(t_entry *this, const char *id, const char **rule)
{
	this->identifier = id;
	this->rule = rule;
	this->next = (void *)0;
}

static

void	parser_init(t_parser *this, const char *str)
{
	char		*saved[3];
	char		*line;
	char		*token;

	saved[0] = str_clone(str);
	line = str_tokenize(saved[0], "\n", &saved[1]);
	while (line != (void *)0)
	{
		parse_line(this, line, &rules);
		line = str_tokenize((void *)0, "\n", &saved[1]);
	}
}