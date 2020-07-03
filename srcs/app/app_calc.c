/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/03 19:32:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_calc(t_app *self)
{

	if (self)
	{
		ft_printf("### CALC\n");

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
		self->ants = queue_create();
		while (self->number)
		{
			if (self->number)
				queue_push_back(self->ants, ant_create(self->number--, r0));
			if (self->number)
				queue_push_back(self->ants, ant_create(self->number--, r42));
		}

	}
}
