#ifndef REGEXP_H
# define REGEXP_H

# include "libds.h"

typedef enum e_pattern_type
{
	GROUP,
	OR,
	CHAR,
	WILDCARD
}t_pattern_type;

typedef enum e_quantifier
{
	DEFAULT,
	MAYBE,
	ZERO_OR_MORE,
	ONE_OR_MORE
}t_quantifier;

typedef struct s_pattern
{
	t_pattern_type	type;
	t_quantifier	quantifier;
}t_pattern;

typedef struct s_group
{
	t_pattern	base;
	t_list		*patterns;
}t_group;

typedef struct s_or
{
	t_pattern	base;
}t_or;

typedef struct s_characater
{
	t_pattern	base;
	char		character;
}t_character;

typedef struct s_wildcard
{
	t_pattern	base;
}t_wildcard;

typedef struct s_regexp
{
	t_list	patterns;
}t_regexp;

t_list	*regexp_parse(const char *regex, int32_t depth);
int		group_open(const char *regex, t_list *stack, int32_t depth, int32_t *idx);
int		group_close(const char *regex, t_list *stack, int32_t depth, int32_t *idx);
int		wildcard(t_list *stack, int32_t *idx);
int		quantifier(t_list *stack, char quantifier, int32_t *idx);
int		character(t_list *stack, char c, int32_t *idx);
void	group_print(t_pattern *pattern, int32_t depth);
void	character_print(t_pattern *pattern, int32_t depth);
void	regexp_print(t_list *regexp, int32_t depth);
void	wildcard_print(t_pattern *pattern, int32_t depth);

#endif
