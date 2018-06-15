#include "lem_in.h"

int		count_linked_rooms(t_room *room)
{
	t_link	*l;
	int		cnt;

	cnt = 1;
	if (!(r && r->link && r->link->room))
		return (0);
	l = r->link;
	while (l->next && l->next->room && (l = l->next))
		++cnt;
	return (cnt);
}
