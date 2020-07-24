/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/24 23:35:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		calc_suurballe_reverse(t_link *link)
{
	t_part		*temp;

	temp = link->part1;
	link->part1 = link->part2;
	link->part2 = temp;
	link->weight = -link->weight;
}

void			calc_suurballe(t_app *self)
{
	t_link		*walk;
	t_link		*link;

	walk = self->room_end->in.link;
	while (walk != (t_link *)TRUE)
	{
		link = walk->part1->link;
		if (walk->weight == 1)
		{
			walk->part2->room->path = walk->part1->room;
		}
		calc_suurballe_reverse(walk);
		walk = link;
	}
	list_push_back(self->paths, self->room_end->path);
}
