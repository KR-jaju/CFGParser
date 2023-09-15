
#include "regexp.h"
#include <stdio.h>
#include "alloc.h"
#include <stdlib.h>

int	group_open(const char *regex, t_list *stack, int32_t depth, int32_t *idx)
{
	t_group*const	pattern = alloc(sizeof(t_group));
	t_list*const	children = ((*idx)++, regexp_parse(regex, depth + 1));

	if (children == (void *)0)
		return (free(pattern), -1);
	pattern->base.quantifier = DEFAULT;
	pattern->base.type = GROUP;
	pattern->patterns = children;
	list_push(stack, &pattern);
	return (0);
}

void	group_print(t_pattern *pattern, int32_t depth)
{
	t_group*const	this = (t_group *)pattern;

	for (int32_t tabs = 0; tabs < depth; tabs++)
		printf("\t");
	printf("{\ntype:group, \n");
	regexp_print(this->patterns, depth + 1);
	if (pattern->quantifier == DEFAULT)
		printf("qualifier:default");
	else if (pattern->quantifier == MAYBE)
		printf("qualifier:?");
	else if (pattern->quantifier == ZERO_OR_MORE)
		printf("qualifier:*");
	else if (pattern->quantifier == ONE_OR_MORE)
		printf("qualifier:+");
	printf("\n}\n");
}
