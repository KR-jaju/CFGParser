
#include <libds.h>
#include "alloc.h"
#include "regexp.h"
#include <stdio.h>

t_list	*regexp_parse(const char *regex, int32_t depth)
{
	static int32_t	idx;
	t_list*const	stack = alloc(sizeof(t_list));
	int				errno;

	errno = 0;
	list_init(stack, sizeof(void *), 16);
	while (regex[idx] != '\0' || (depth != 0 && regex[idx] != ')'))
	{
		if (regex[idx] == '.')
			errno = wildcard(stack, &idx);
		else if (regex[idx] == '?' || regex[idx] == '+' || regex[idx] == '*')
			errno = quantifier(stack, regex[idx], &idx);
		else if (regex[idx] == '(')
			errno = group_open(regex, stack, depth, &idx);
		else
			errno = character(stack, regex[idx], &idx);
		if (errno == -1)
			return ((void *)0); //TODO: Drop List
	}
	if (depth != 0)
		idx++;
	return (stack);
}

static
bool	test_local(t_pattern *pattern, const char **str);

static
int	quantify(t_list *regexp, const char *str, int32_t idx)
{
	t_pattern	*pattern;

	if (idx >= regexp->count)
		return (0);
	list_get(regexp, idx, &pattern);
	if (pattern->quantifier == DEFAULT)
		return 
}

int	regexp_test(t_list *regexp, const char *str)
{

}

void	regexp_print(t_list *regexp, int32_t depth)
{
	t_pattern	*pattern;

	for (uint32_t i = 0; i < regexp->count; i++)
	{
		list_get(regexp, i, &pattern);
		if (i != 0)
			printf(",");
		if (pattern->type == GROUP)
			group_print(pattern, depth);
		else if (pattern->type == CHAR)
			character_print(pattern, depth);
		else if (pattern->type == WILDCARD)
			wildcard_print(pattern, depth);
	}
}

