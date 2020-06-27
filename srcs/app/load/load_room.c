/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 21:30:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_memdel((void **)aself);
	}
}

int		room_parse(t_room *room, char *line)
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

int		load_room(t_app *self)
{
	t_room	*room;

	if (self->signal_start && self->signal_end)
		app_error(self);
	room = room_create();
	if (room_parse(room, self->line))
	{
		// GOOD ROOM
		if (self->signal_start)
			ft_printf("START ");
		if (self->signal_end)
			ft_printf("END ");
		ft_printf("ROOM: %s\n", room->name);
		room_destroy(&room);
		self->signal_start = 0;
		self->signal_end = 0;
		return (1);
	}
	room_destroy(&room);
	return (0);
}
