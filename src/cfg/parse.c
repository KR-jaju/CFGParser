
#include <stdint.h>

#define OR 129
#define END 130

static
int32_t	**grammar(void)
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

int32_t	**parse_cfg(const char *str)
{

}

