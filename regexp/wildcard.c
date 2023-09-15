
#include "regexp.h"
#include "libds.h"
#include <stdint.h>
#include "alloc.h"
#include <stdio.h>

int	wildcard(t_list *stack, int32_t *idx)
{
	t_wildcard*const	pattern = alloc(sizeof(t_wildcard));

	pattern->base.quantifier = DEFAULT;
	pattern->base.type = WILDCARD;
	list_push(stack, &pattern);
	(*idx)++;
	return (0);
}

void	wildcard_print(t_pattern *pattern, int32_t depth)
{
	t_wildcard*const	this = (t_wildcard *)pattern;

	for (int32_t tabs = 0; tabs < depth; tabs++)
		printf("\t");
	if (this->base.quantifier == DEFAULT)
		printf("{\ntype:wildcard,\nquantifier:default\n}\n");
	else if (this->base.quantifier == MAYBE)
		printf("{\ntype:wildcard,\nquantifier:maybe\n}\n");
	else if (this->base.quantifier == ZERO_OR_MORE)
		printf("{\ntype:wildcard,\nquantifier:*\n}\n");
	else if (this->base.quantifier == ONE_OR_MORE)
		printf("{\ntype:wildcard,\nquantifier:+\n}\n");
}
