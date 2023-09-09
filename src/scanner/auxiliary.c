
#include <cfg.h>
#include <stdbool.h>
#include <libft.h>

static
void	*null_guard(void *ptr)
{
	if (ptr == (void *)0)
		exit(1);
	return (ptr);
}

void	skip_space(t_scanner *scanner)
{
	const char	*str = &scanner->str[scanner->cursor];
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n')
		i++;
	scanner->cursor += i;
}
