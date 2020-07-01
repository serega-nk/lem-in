/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:50:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		play(t_app *self)
{
	t_ant	*ant;
	int		count;

	while (queue_walk_start(self->ants))
	{
		count = 0;
		while (queue_walk_next(self->ants, (void **)&ant))
		{
			if (ant_move(ant))
			{
				ant_output(ant, count++);
				if (ant_finish(ant))
					queue_walk_remove(self->ants, &ant_destroy);
			}
		}
		ft_printf("\n");
		if (count == 0)
		{
			ft_printf("FATAL ");
			app_error(self);
		}
	}
}

void			app_play(t_app *self)
{

	t_room *r0, *r1, *r2, *r3, *r42, *r21;
	r0 = r42 = NULL;
	if (hashtab_get(self->rooms, "0", (void **)&r0) &&
		hashtab_get(self->rooms, "1", (void **)&r1) &&
		hashtab_get(self->rooms, "2", (void **)&r2) &&
		hashtab_get(self->rooms, "3", (void **)&r3) && 
		hashtab_get(self->rooms, "42", (void **)&r42) &&
		hashtab_get(self->rooms, "21", (void **)&r21))
	{
		r0->path = r1;
		r1->path = r2;
		r2->path = r3;
		r42->path = r21;
		r21->path = r3;
	}
	
	while (queue_pop_front(self->lines, (void **)&self->line))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
	ft_printf("\n");
	ft_printf("NUMBER OF ANTS = %d\n", self->number);
	self->ants = queue_create();
	while (self->number)
	{
		if (self->number)
			queue_push_back(self->ants, ant_create(self->number--, r0));
		if (self->number)
			queue_push_back(self->ants, ant_create(self->number--, r42));
	}
	play(self);
}
