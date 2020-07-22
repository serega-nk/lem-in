/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:10:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/22 05:05:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_shortest_clean(t_app *self)
{
	t_room	*room;

	hashtab_start(self->rooms);
	while (hashtab_next_kv(self->rooms, NULL, (void **)&room))
	{
		room_reset(room);
	}
	self->room_start->in.link = (t_link *)TRUE;
}

static t_bool	calc_shortest_update(t_save *source, t_save *dest,
	t_link *link, int weight)
{
	int			level;

	if (source->link)
	{
		level = source->level + weight;
		if (dest->link == NULL || dest->level > level)
		{
			// if (link->type == LINK_REVERSE)
			// {
			// 	ft_printf("# UPDATE LINK_REVERSE %s, %s   weight = %d, level = %d\n", link->room1->name, link->room2->name, weight, level);
			// }
			// else
			// {
			// 	ft_printf("# UPDATE LINK_EDGE %s, %s   weight = %d, level = %d\n", link->room1->name, link->room2->name, weight, level);
			// }
					
			dest->level = level;
			dest->link = link;
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	calc_shortest_while(t_app *self, t_link *link)
{
	t_bool		update;
	t_save		*source;

	update = FALSE;
	if (link->type == LINK_EDGE)
	{
		source = link->room1->path ? &link->room1->out : &link->room1->in;
		if (calc_shortest_update(source, &link->room2->in, link, 1))
			update = TRUE;
		source = link->room2->path ? &link->room2->out : &link->room2->in;
		if (calc_shortest_update(source, &link->room1->in, link, 1))
			update = TRUE;
	}
	else if (link->type == LINK_REVERSE)
	{
		if (calc_shortest_update(&link->room2->in, &link->room1->out, link, -1))
			update = TRUE;
		if (calc_shortest_update(&link->room1->out, &link->room1->in, link, 0))
			update = TRUE;
	}
	else if (link->type == LINK_NONE)
	{

	}
	else
	{
		
		app_error(self);
	}
	return (update);
}

static t_bool	calc_shortest_result(t_app *self)
{
	t_link		*link;

	link = self->room_end->in.link;
	if (link)
	{
		if (link->room2 == self->room_end)
			list_push_back(self->paths, link->room1);
		else
			list_push_back(self->paths, link->room2);
		return (TRUE);
	}
	return (FALSE);
}

t_bool			calc_shortest(t_app *self)
{
	size_t		index;
	t_bool		update;
	t_list_iter	*iter;
	t_link		*link;

	calc_shortest_clean(self);
	index = 0;
	update = TRUE;
	while (update)
	{
		update = FALSE;
		iter = list_iter_create(self->links);
		while (list_iter_next(iter, (void *)&link))
		{
			if (calc_shortest_while(self, link))
				update = TRUE;
		}
		list_iter_destroy(&iter);
		if (index == self->links->count)
			app_error(self);
		index++;
	}
	return (calc_shortest_result(self));
}
