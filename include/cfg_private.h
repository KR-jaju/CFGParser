
#ifndef CFG_PRIVATE_H
# define CFG_PRIVATE_H

/*

-129 = |
-130 = end of line

0 : <cfg> -> < \n+> <rule> <cfg> | ""
1 : <rule> -> <non-term> < +> '-' '>' < \n+> <expr_list>
2 : <expr_list> -> <expr> < \n+> "|" < \n+> <expr_list> | ""
3 : <expr> -> <element> < \n+> <expr> | <element> < \n+>
4 : <element> -> <non-term> | <string>
5 : <char> -> 'a' | 'b' | 'c' | 'd' | 'e' |.....
6 : <char*> -> <char> <char*> | '\0'
7 : <string> -> "\"" <char>* "\""
8 : < \n> -> (' ' | '\n')
9 : < \n+> -> < \n> < \n+> | '\0'
10 : <non-term> -> '<' <char*> '>'


0 -> 9 1 0 OR '\0' END
1 -> 10 9 '-' '>' 9 2 END
2 -> 3 9 '|' 9 2 OR '\0' END
3 -> 4 9 3 OR 4 9 END
4 -> 10 OR 7 END
5 -> 'a' OR 'b' OR ....
6 -> 5 6 OR '\0' END
7 -> '\"' 6 '\"' END
8 -> ' ' OR '\n END
9 -> 8 9 | '\0' END
10 -> '<' 6 '>' END


		(int32_t []){~10, ~9, '-', '>', ~0, ~2, END},
		(int32_t []){~3, ~9, '|', ~9, ~2, OR, ~ '\0', END},
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

*/

// !! malloc 보호 없음 !!

typedef struct s_grammar
{
	char	**non_terms;
	
}t_grammar;

typedef struct s_node
{
	char	*str;
	t_node	*children;
}t_node;

int	non_term(const char **str_ref, t_node *node);
int	string_term(const char **str_ref, t_node *node);
int	void_term(const char**str_ref, t_node *node);
int	pipe_term(const char **str_ref, t_node *node);
int	arrow_term(const char **str_ref, t_node *node);


int	cfg_element(const char **str_ref, t_node *out);

int	cfg_expr(const char **str_ref, t_node *out);

// int32_t

#endif
