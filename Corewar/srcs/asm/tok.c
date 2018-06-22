#include "asm.h"

void	tok_tostring(t_tok *tok)
{
	printf("[TOKEN %s][LABEL %s][LINE %d][POS %d]",
		tok->type, tok->label, tok->nbl, toke->pos);
}

t_tok	*new_tok()
{
	t_tok	*new;
	
	if ((new = (t_tok *)malloc(sizeof(t_tok))) == NULL)
		return (NULL);
	new->type = -1;
	new->label = NULL;
	new->nbl = -1;
	new->pos = 0;
	new->list = NULL;
	new->next = NULL;
	return (new);
}

t_tok	*create_tok(int type, char *label, int nbl, int pos)
{
	t_tok	*tok;

	if ((tok = new_tok()) == NULL)
		return (NULL);
	tok->type = type;
	new->label = ft_strdup(label);
	new->nbl = nbl;
	new->pos = pos;
	return (tok);
}
