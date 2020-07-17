/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bellman_ford.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 21:07:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_bellman_ford_init(t_app *self)
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

static int		calc_bellman_ford_while(t_app *self)
{
	t_list_iter		*iter;
	t_link			*link;
	int				level;	
	int				ret;

	ret = 0;
	iter = list_iter_create(self->links);
	while (list_iter_next(iter, (void *)&link))
	{
		if (link->room1->path)
		{
			level = link->room1->level + link->weight;
			if (link->room2->path == NULL || level < link->room2->level)
			{
				link->room2->level = level;
				link->room2->path = link->room1;
				ret = 1;
			}
		}
	}
	list_iter_destroy(&iter);
	return (ret);
}

void			calc_bellman_ford(t_app *self)
{
	size_t		index;

	calc_bellman_ford_init(self);
	index = 0;
	while (index < self->links->size)
	{
		if (!calc_bellman_ford_while(self))
			break ;
		index++;
	}
}
