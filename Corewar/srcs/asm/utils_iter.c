#include "asm.h"

t_header	iter_head(t_iter *iter)
{
	t_header	head;
	t_tok		*tok;

	tok = NULL;
	if (iter)
	{
		tok = iter->first;
		while (tok)
		{
			if (tok->type = 1)
				;
			tok = tok->next;
		}
	}
	return (head);
}
