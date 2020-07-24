/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/24 17:06:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


// static t_link	*calc_suurballe_next(t_link *walk)
// {
// 	t_link		*next;
// 	t_part		*temp;

// 	next = walk->part1->link;
// 	if (walk->weight == -1)
// 	{
// 		if ()
// 		walk->remove = TRUE;
// 	}
// 	else
// 	{
// 		// if (walk->part2->type == PART_IN &&
// 		// 	walk->part1->type == PART_OUT &&
// 		// 	walk->part2->room != walk->part1->room)
// 		if (walk->part2->room != walk->part1->room)
// 		{
// 			walk->part2->room->path = walk->part1->room;
// 		}
// 		temp = walk->part1;
// 		walk->part1 = walk->part2;
// 		walk->part2 = temp;
//         walk->weight = -walk->weight;
// 	}
// 	return (next);
// }

void			calc_suurballe(t_app *self)
{
	t_link		*prev;
	t_link		*walk;
	t_link		*next;
	t_part		*temp;
	
	prev = NULL;
	walk = self->room_end->in.link;
	while (walk != (t_link *)TRUE)
	{
		next = walk->part1->link;
		if (walk->weight == -1)
		{
			walk->remove = TRUE;
		}
		else
		{
			if (walk->part2->room != walk->part1->room)
			{
				walk->part2->room->path = walk->part1->room;
			}
			temp = walk->part1;
			walk->part1 = walk->part2;
			walk->part2 = temp;
			walk->weight = -walk->weight;
		}
		//ft_printf("### walk %p, %s ---> %s\n", walk, walk->part1->room->name, walk->part2->room->name);
		//walk = calc_suurballe_next(walk);
		prev = walk;
		walk = next;
	}
	//ft_printf("### path == %s\n", self->room_end->path->name);
	list_push_back(self->paths, self->room_end->path);
}
