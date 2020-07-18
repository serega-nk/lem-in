/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 17:45:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_suurballe_remove_link(t_room *room1, t_room *room2)
{
	t_link	*link;

	if (hashtab_remove(room1->links, room2->name, (void **)&link))
	{
		link->remove = 1;
	}
}

static void		calc_suurballe_insert_link(t_app *self, t_link *link)
{
	list_push_back(self->links, link);
	if (!hashtab_insert(link->room1->links, link->room2->name, link))
	{
		app_error(self);
	}
}

static void		calc_suurballe_swap_links(t_room *room1, t_room *room2)
{
	t_hashtab	*temp;
	t_link		*link;

	temp = room1->links;
	room1->links = room2->links;
	room2->links = temp;
	hashtab_start(room1->links);
	while (hashtab_next_kv(room1->links, NULL, (void **)&link))
		link->room1 = room1;
	hashtab_start(room2->links);
	while (hashtab_next_kv(room2->links, NULL, (void **)&link))
		link->room1 = room2;
}

static t_room	*calc_suurballe_split_room(t_app *self, t_room *path)
{
	t_room		*room;

	room = room_create();
	room->name = ft_xstrdup2("[out] ", path->name);
	if (!hashtab_insert(self->rooms, room->name, (void *)room))
	{
		room_destroy(&room);
		app_error(self);
	}
	room->type = TYPE_OUT;
	path->type = TYPE_IN;
	calc_suurballe_swap_links(room, path);
	return (room);
}

void			calc_suurballe(t_app *self)
{
	t_room	*walk;
	t_room	*room;

	walk = self->room_end;
	list_push_back(self->paths, walk->path);
	while (walk->type != TYPE_START)
	{
		calc_suurballe_remove_link(walk, walk->path);
		calc_suurballe_remove_link(walk->path, walk);
		if (walk->path->type == TYPE_START || walk->path->type == TYPE_OUT)
		{
			walk->route = walk->path;
		}
		else if (walk->path->type == TYPE_ROOM)
		{
			room = calc_suurballe_split_room(self, walk->path);
			calc_suurballe_insert_link(self, link_create(walk, room, -1));
			calc_suurballe_insert_link(self, link_create(room, walk->path, 0));
			walk->path->route = NULL;
			room->route = walk->path;
			walk->route = room;
		}			
		walk = walk->path;
	}
}
