/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bellman_ford.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 17:49:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_bellman_ford_clean(t_app *self)
{
	t_room		*room;

	hashtab_start(self->rooms);
	while (hashtab_next_kv(self->rooms, NULL, (void **)&room))
	{
		room->level = 0;
		room->path = NULL;
	}
	self->room_start->path = self->room_start;
}

static int		calc_bellman_ford_update(t_app *self)
{
	t_list_iter		*iter;
	t_link			*link;
	int				level;	
	int				update;

	update = 0;
	iter = list_iter_create(self->links);
	while (list_iter_next(iter, (void *)&link))
	{
		if (link->remove)
		{
			ft_printf("# REMOVE LINK   %s => %s == %d\n", link->room1->name, link->room2->name, link->weight);
			list_iter_remove(iter, &link_destroy);
		}
		else if (link->room1->path)
		{
			level = link->room1->level + link->weight;
			if (link->room2->path == NULL || level < link->room2->level)
			{
				link->room2->level = level;
				link->room2->path = link->room1;
				update = 1;
			}
		}
	}
	list_iter_destroy(&iter);
	return (update);
}

int		calc_bellman_ford(t_app *self)
{
	size_t		index;

	calc_bellman_ford_clean(self);
	index = 0;
	while (index < self->links->size)
	{
		if (!calc_bellman_ford_update(self))
			break ;
		index++;
	}
	return (self->room_end->path != NULL);
}
