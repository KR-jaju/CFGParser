
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

int	number_token(t_scanner *scanner)
{
	const char	*str = &scanner->str[scanner->cursor];
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		while ('0' <= str[i] && str[i] <= '9')
			i++;
	}
	return (scanner->look_ahead = (t_token){
		"Number",
		null_guard(ft_substr(str, 0, i))
	}, 0);
}
