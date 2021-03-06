/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bellman_ford.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 23:12:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	calc_bellman_ford_clean(t_app *self)
{
	t_room		*room;

	hashtab_start(self->rooms);
	while (hashtab_next_kv(self->rooms, NULL, (void **)&room))
	{
		room->out.link = NULL;
		room->out.cost = 0;
		room->in.link = NULL;
		room->in.cost = 0;
	}
	self->room_start->out.link = (t_link *)TRUE;
}

static inline int	calc_bellman_ford_update(t_app *self)
{
	t_bool		update;
	t_list_iter	*iter;
	t_link		*link;
	int			cost;

	update = FALSE;
	iter = list_iter_create(self->links);
	while (list_iter_next(iter, (void *)&link))
	{
		if (link->part1->link)
		{
			cost = link->part1->cost + link->weight;
			if (link->part2->link == NULL || link->part2->cost > cost)
			{
				link->part2->link = link;
				link->part2->cost = cost;
				update = TRUE;
			}
		}
	}
	list_iter_destroy(&iter);
	return (update);
}

t_bool				calc_bellman_ford(t_app *self)
{
	size_t		index;

	calc_bellman_ford_clean(self);
	index = 0;
	while (index < self->rooms->count)
	{
		if (!calc_bellman_ford_update(self))
			break ;
		index++;
	}
	return (self->room_end->in.link != NULL);
}
