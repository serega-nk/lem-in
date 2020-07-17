/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bellman_ford.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 20:26:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_bellman_ford_clean(t_app *self)
{
	t_room	*room;

	hashtab_start(self->rooms);
	while (hashtab_next_kv(self->rooms, NULL, (void **)&room))
	{
		room->level = 0;
		room->path = NULL;
	}
}

void			calc_bellman_ford(t_app *self)
{
	calc_bellman_ford_clean(self);
}
