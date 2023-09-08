
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

int	auxiliary_token(t_scanner *scanner)
{
	const char	*str = &scanner->str[scanner->cursor];
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n')
	{
		i++;
	}
	if (i == 0)
		return (-1);
	return (scanner->look_ahead = (t_token){
		"Auxiliary",
		null_guard(ft_substr(str, 0, i))
	}, 0);
}
