/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_disjoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:12:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 20:44:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*calc_disjoint_link(t_room *room)
{
	if (room->path &&
		room->in.link && room->out.link &&
		room->in.level >= room->out.level)
	{
		return (room->out.link);
	}
	else
	{
		return (room->in.link);
	}
}

void			calc_disjoint(t_app *self)
{
	t_room		*room;
	t_link		*link;
	t_list		*list;

	list = list_create();

	room = self->room_end;
	while (room != self->room_start)
	{
		link = calc_disjoint_link(room);
		if (link->type == LINK_EDGE)
		{
			if (link->room2 == room)
			{
				link->room2 = link->room1;
				link->room1 = room;
			}
			//link->type = LINK_REVERSE;
			list_push_back(list, link);
			room->path = link->room2;
			room = link->room2;
		}
		else if (link->type == LINK_REVERSE)
		{
			
			//link->type = LINK_NONE;
			list_push_back(list, link);
			link->room1->path = NULL;
			room = link->room1;
		}
		else
			app_error(self);
	}
	t_list_iter *iter;
	iter = list_iter_create(list);
	while (list_iter_next(iter, (void *)&link))
	{
		// if (link->type == LINK_REVERSE)
		// 	ft_printf("# LINK_REVERSE = %p\n", link);
		// link->type = LINK_REVERSE;
		link->type = LINK_NONE;
	}
	list_iter_destroy(&iter);	
}
