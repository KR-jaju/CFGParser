
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

int	keyword_token(t_scanner *scanner)
{
	const char	*str = &scanner->str[scanner->cursor];
	char const	*keywords[] = {
		"A",
		"C",
		"L",
		"sp",
		"pl",
		"cy"
	};
	int			i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(str, keywords[i], ft_strlen(keywords[i])) == 0)
			return (scanner->look_ahead = (t_token){
				TK_KEYWORD,
				null_guard(ft_strdup(keywords[i]))
			}, 0);
		i++;
	}
	return (-1);
}
