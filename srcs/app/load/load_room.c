/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 03:34:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_room_parse(t_app *self, t_room *room)
{
	char	*line;

	line = self->line;
	if (parse_str(&line, &room->name, "- \n") &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_x) &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_y) &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
		return (1);
	return (0);
}

static int	load_room_insert(t_app *self, t_room *room)
{
	if (self->signal_start && self->signal_end)
		return (0);
	if (room->name[0] != 'L' &&
		room->coord_x >= 0 &&
		room->coord_y >= 0 &&
		hashtab_insert(self->rooms, room->name, room))
	{
		if (self->signal_start)
		{
			room->type = TYPE_START;
			self->room_start = room;
			self->signal_start = 0;			
		}
		if (self->signal_end)
		{
			room->type = TYPE_END;
			self->room_end = room;
			self->signal_end = 0;
		}
		return (1);
	}
	return (0);
}

int			load_room(t_app *self)
{
	t_room	*room;

	room = room_create();
	if (!load_room_parse(self, room))
	{
		room_destroy(&room);
		return (0);
	}
	if (!load_room_insert(self, room))
	{
		room_destroy(&room);
		app_error(self);
	}
	return (1);
}
