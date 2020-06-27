/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:15:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_room_parse(t_room *room, char *line)
{
	if (parse_str(&line, &room->name, "- ") &&
		room->name[0] != 'L' &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_x) &&
		parse_skip(&line, " ") &&
		parse_int(&line, &room->coord_y) &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
		return (1);
	return (0);
}

int			load_room(t_app *self)
{
	t_room	*room;

	if (self->signal_start && self->signal_end)
		app_error(self);
	room = room_create();
	if (load_room_parse(room, self->line))
	{
		if (self->signal_start)
			self->room_start = room;
		if (self->signal_end)
			self->room_end = room;
		queue_push_back(self->rooms, room);
		self->signal_start = 0;
		self->signal_end = 0;
		return (1);
	}
	room_destroy(&room);
	return (0);
}
