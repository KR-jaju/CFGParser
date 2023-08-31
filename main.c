/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaju <jaju@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:51:25 by jaju              #+#    #+#             */
/*   Updated: 2023/08/31 15:00:00 by jaju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cfg.h>
#include <unistd.h>
#include <fcntl.h>

char	*read_file(const char *path)
{
	static char content[2048];
	int	fd = open(path, O_RDONLY);

	int end = read(fd, content, 2047);
	end = content[end] = '\0';]
	return (content);
}

void	print_rule(t_rule *rule)
{
	int	i;

	i = 0;
	printf("%s:\n", rule->identifier);
	while (i < rule->epxr_list.length)
	{
		printf("	%d\n", list_get(&rule->epxr_list, i));
		i++;
	}
}

int	main(void)
{
	t_parser	parser;
	const char	*start;
	t_entry		*ent;

	parser_init(&parser, read_file("rt.cfg"));
	ent = parser.rules.entries;
	while (ent != (void *)0)
	{
		print_rule(ent->value);
		ent = ent->next;
	}
}