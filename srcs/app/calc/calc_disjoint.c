/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_disjoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:12:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 21:09:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*calc_disjoint_link(t_room *room)
{
	if (room->path &&
		room->in.link && room->out.link &&
		room->in.level <= room->out.level)
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
	t_list		*list_rev;
	t_list		*list_non;

	list_rev = list_create();
	list_non = list_create();

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
			list_push_back(list_rev, link);
			room->path = link->room2;
			room = link->room2;
		}
		else if (link->type == LINK_REVERSE)
		{
			//link->type = LINK_NONE;
			//list_push_back(list_non, link);
			link->room1->path = NULL;
			room = link->room1;
		}
		else
			app_error(self);
	}	
	
	t_list_iter *iter;
	
	iter = list_iter_create(list_rev);
	while (list_iter_next(iter, (void *)&link))
	{
		link->type = LINK_REVERSE;
	}
	list_iter_destroy(&iter);
	
	iter = list_iter_create(list_non);
	while (list_iter_next(iter, (void *)&link))
	{
		link->type = LINK_NONE;
		link->room1->path = NULL;
	}
	list_iter_destroy(&iter);

	list_destroy(&list_non);
	list_destroy(&list_rev);
}
