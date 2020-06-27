/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:25:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		links_destroy(t_queue **aself)
{
	void	*data;

	while ((data = queue_pop_front(*aself)))
		;
	queue_destroy(aself);
}

static void		rooms_destroy(t_queue **aself)
{
	t_room	*room;

	while ((room = queue_pop_front(*aself)))
		room_destroy(&room);
	queue_destroy(aself);
}

static void		lines_destroy(t_queue **aself)
{
	char	*line;

	while ((line = queue_pop_front(*aself)))
		ft_strdel(&line);
	queue_destroy(aself);
}

void			app_free(t_app *self)
{
	gnl_destroy(&self->gnl);
	links_destroy(&self->links);
	rooms_destroy(&self->rooms);
	lines_destroy(&self->lines);
}
