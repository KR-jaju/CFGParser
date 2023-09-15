
#include "regexp.h"

int	main(void)
{
	t_list	*regex = regexp_parse("a+(b*c)*", 0);

	regexp_print(regex, 0);
}
