/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 04:48:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		links_destroy(t_queue **aself)
{
	t_link	*link;

	while ((link = queue_pop_front(*aself)))
		link_destroy(&link);
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
	ft_strdel(&self->temp);
	gnl_destroy(&self->gnl);
	links_destroy(&self->links);
	hashtab_destroy(&self->coords);
	hashtab_clean(self->rooms, &room_destroy);
	hashtab_destroy(&self->rooms);
	lines_destroy(&self->lines);
}
