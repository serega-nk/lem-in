
#include "lem_in.h"

t_room	*room_create(void)
{
	t_room	*self;

	self = (t_room *)ft_xmemalloc(sizeof(t_room));
	return (self);
}

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		ft_strdel(&(*aself)->key_coord);
		ft_memdel((void **)aself);
	}
}

t_link	*link_create(void)
{
	t_link	*self;

	self = (t_link *)ft_xmemalloc(sizeof(t_link));
	return (self);
}

void	link_destroy(t_link **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name1);
		ft_strdel(&(*aself)->name2);
		ft_memdel((void **)aself);
	}
}
