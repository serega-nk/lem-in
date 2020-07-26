/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 23:10:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	calc_suurballe_path(t_link *link)
{
	t_room	*room_out;
	t_room	*room_in;

	if (link->weight == 1)
	{
		room_out = link->part1->room;
		room_in = link->part2->room;
		room_in->path = room_out;
	}
}

static inline void	calc_suurballe_reverse(t_link *link)
{
	t_part		*temp;

	temp = link->part1;
	link->part1 = link->part2;
	link->part2 = temp;
	link->weight = -link->weight;
}

void				calc_suurballe(t_app *self)
{
	t_link		*walk;
	t_link		*next;

	walk = self->room_end->in.link;
	while (walk != (t_link *)TRUE)
	{
		next = walk->part1->link;
		calc_suurballe_path(walk);
		calc_suurballe_reverse(walk);
		walk = next;
	}
	list_push_back(self->paths, self->room_end->path);
}
