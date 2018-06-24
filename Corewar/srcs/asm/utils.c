#include "asm.h"

void	clear_wsp(t_iter *iter)
{	
	while (*iter->line && ft_isspace(*iter->line))
	{
		++(iter->count);
		++(iter->line);
	}
}
