
#include "lem_in.h"

t_room	*room_create(void)
{
	t_room	*self;

	self = (t_room *)ft_xmemalloc(sizeof(t_room));
	self->links = hashtab_create();
	return (self);
}

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		hashtab_destroy(&(*aself)->links);
		ft_memdel((void **)aself);
	}
}
