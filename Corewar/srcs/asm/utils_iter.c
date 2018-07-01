#include "asm.h"

static int	head_get(t_header *head, char *line, int boolean)
{
	int		count;
	char	*dup;

	count = 0;
	dup = line;
	if (line)
	{
		while (*dup && *dup != '"')
			++dup;
		if (*dup == '"')
		{
			++dup;
			while (*dup && *dup != '"')
			{
				if (boolean) 
					head->prog_name[count] = *dup;
				else
					head->comment[count] = *dup;
				++dup;
				++count;
				printf("%s\n", head->comment);
				printf("%s\n", head->prog_name);
			}
			if (*dup == '"')
				return (1);
		}
	}
	return (0);
}

void	iter_head(char *line, t_iter *iter)
{
	t_tok		*tok;

	tok = NULL;
	if (iter)
	{
		tok = iter->first;
		//error here
		while (tok)
		{
			if (tok->type == 0x84 || tok->type == 0x82)
			{
				printf("%s\n", line);
				head_get(&iter->header, line, tok->type == 0x82);
			}
			tok = tok->next;
		}
	}
}
