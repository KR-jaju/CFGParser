
#include "regexp.h"
#include "libds.h"

int	quantifier(t_list *stack, char quantifier, int32_t *idx)
{
	t_pattern	*pattern;

	if (quantifier != '?' && quantifier != '*' && quantifier != '+')
		return (-1);
	if (stack->count == 0)
		return (-1);
	list_get(stack, stack->count - 1, &pattern);
	if (pattern->quantifier != DEFAULT)
		return (-1);
	if (quantifier == '?')
		pattern->quantifier = MAYBE;
	else if (quantifier == '+')
		pattern->quantifier = ONE_OR_MORE;
	else if (quantifier == '*')
		pattern->quantifier = ZERO_OR_MORE;
	(*idx)++;
	return (0);
}
