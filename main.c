
#include <cfg.h>
#include <stdio.h>

int	main(void)
{
	t_scanner	scanner;

	scanner_init(&scanner, "cy pl A 3.141592gggh");
	while (scanner_has_next(&scanner))
	{
		t_token*const tk = scanner_next(&scanner);
		printf("Type: %s, Value : %s \n", tk->type, tk->lexeme);
		free(tk);
	}
}

