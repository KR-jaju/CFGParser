
#include "regexp.h"
#include "regexp.h"
#include <alloc.h>
#include <stdio.h>


int	character(t_list *stack, char c, int32_t *idx)
{
	t_character*const	pattern = alloc(sizeof(t_character));

	pattern->base.quantifier = DEFAULT;
	pattern->base.type = CHAR;
	pattern->character = c;
	list_push(stack, &pattern);
	(*idx)++;
	return (0);
}

void	character_print(t_pattern *pattern, int32_t depth)
{
	t_character*const	this = (t_character *)pattern;

	for (int32_t tabs = 0; tabs < depth; tabs++)
		printf("\t");
	printf("{\ntype:character,\n");
	if (this->base.quantifier == DEFAULT)
		printf("value:%c,\nquantifier:default\n", this->character);
	else if (this->base.quantifier == MAYBE)
		printf("value:%c,\nquantifier:maybe\n", this->character);
	else if (this->base.quantifier == ZERO_OR_MORE)
		printf("value:%c,\nquantifier:*\n", this->character);
	else if (this->base.quantifier == ONE_OR_MORE)
		printf("value:%c,\nquantifier:+\n", this->character);
	printf("}\n");
}
