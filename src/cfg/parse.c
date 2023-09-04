
#include <stdint.h>
#include <cfg.h>

#define OR 129
#define END 130

static
int32_t	**cfg_grammar(void)
{
	static int32_t	**table = {
		(int32_t []){~9, ~1, ~0, OR, '\0', END},
		(int32_t []){~10, ~9, '-', '>', ~0, ~2, END},
		(int32_t []){~3, ~9, '|', ~9, ~2, OR, '\0', END},
		(int32_t []){~4, ~9, ~3, OR, ~4, ~9, END},
		(int32_t []){~10, OR, ~7, END},
		(int32_t []){'a', OR, 'b', OR, 'c', OR, 'd', OR, 'e',
		OR, 'f', OR, 'g', OR, 'h', OR, 'i', OR, 'i', OR, 'j',
		OR, 'k', OR, 'l', OR, 'm', OR, 'p', OR, 'q', OR, 'r',
		OR, 's', OR, 't', OR, 'u', OR, 'v', OR, 'w', OR, 'x',
		OR, 'y', OR, 'z', OR, '_', END},
		(int32_t []){~5, ~6, OR, '\0', END},
		(int32_t []){'\"', ~6, '\"', END},
		(int32_t []){' ', OR, '\n', END},
		(int32_t []){~8, ~9, OR, '\0', END},
		(int32_t []){'<', ~6, '>', END}
	};

	return (table);
}

static
int32_t	expr_len(int32_t *expr)
{
	int32_t	len;

	len = 0;
	while (expr[len] != END && expr[len] != OR)
		len++;
	return (len);
}

int	parse_char(const char**str_ref, char c, t_node *out)
{
	if (**str_ref != c)
		return (-1);
	//*out = malloc(sizeof(t_node));
	out->c = c;
	out->children = (void *)0;
	return (0);
}

int	parse_local(const char **str_ref, int32_t **grammar, int32_t *expr, t_node *self)
{
	const char		*str = *str_ref;
	t_node*const	children = malloc(expr_len(expr));
	int				i;

	i = 0;
	while (expr[i] != END && expr[i] != OR)
	{
		if (expr[i] < 0)
			if (parse_local(&str, grammar, grammar[~expr[i]], &children[i]) == -1)
				return (free_all(children), -1);
		else
			if (parse_char(str_ref, (char)expr[i], &children[i]) == -1)
				return (free_all(children), -1);
		i++;
	}
	self->children = children;
	self->c = '\0';
}

t_node	*parse(const char *str, int32_t **grammar)
{
	
}
