
#include <cfg.h>
#include <stdlib.h>

int	keyword_token(t_scanner *scanner);
int	number_token(t_scanner *scanner);
void	skip_space(t_scanner *scanner);


void	scanner_init(t_scanner *this, const char *str)
{
	this->str = ft_strdup(str); // GUARD REQUIRE
	this->cursor = 0;
	this->look_ahead = (t_token){(void *)0, (void *)0};
}

bool	scanner_has_next(t_scanner *this)
{
	skip_space(this);
	if (this->look_ahead.type != (void *)0)
		return (true);
	else
	{
		if (keyword_token(this) == 0)
			return (true);
		if (number_token(this) == 0)
			return (true);
	}
	this->look_ahead.type = (void *)0;
	return (false);
}

// t_token	*scanner_peek(const t_scanner *this)
// {
	
// }

t_token	*scanner_next(t_scanner *this)
{
	t_token	*token;

	if (this->look_ahead.type == (void *)0)
	{
		if (!scanner_has_next(this))
			return ((void *)0);
	}
	this->cursor += ft_strlen(this->look_ahead.lexeme);
	token = malloc(sizeof(t_token));
	*token = this->look_ahead;
	this->look_ahead = (t_token){(void *)0, (void *)0};
	return (token);
}
