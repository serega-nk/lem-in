/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_suurballe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:59:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 23:02:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static t_link	*calc_suurballe_next(t_app *self, t_link *walk)
{
	t_link		*next;
	t_part		*temp;

	next = walk->part1->link;
	if (walk->weight == -1)
	{

	}
	else
	{
		if (walk->part2->type == PART_IN &&
			walk->part1->type == PART_OUT &&
			walk->part2->room != walk->part1->room)
		{
			walk->part2->room = walk->part1->room;
		}
		temp = walk->part1;
		walk->part1 = walk->part2;
		walk->part2 = temp;
        walk->weight = -walk->weight;
	}
	return (next);
}

void			calc_suurballe(t_app *self)
{
	t_link	*walk;

	walk = self->room_end->in.link;
	while (walk != (t_link *)TRUE)
	{
		walk = calc_suurballe_next(self, walk);
	}
	list_push_back(self->paths, self->room_end->path);
}




def suurballe(self, debug=False):
    walk = self.room_end.part_in.link
    while walk != True:
        # if debug:
        #     print(walk)
        
        
        link = walk.part1.link

        #print(walk)

        if walk.weight == -1:
            #print('REMOVE', walk)
            self.links.remove(walk)
        else:
            part = walk.part2
            if walk.part2.type == PART_IN and walk.part1.type == PART_OUT and walk.part2.room != walk.part1.room:
                room1 = walk.part2.room
                room2 = walk.part1.room
                room1.path = room2
                #print('###', walk, room1, room2)

            walk.part1, walk.part2 = walk.part2, walk.part1
            walk.weight = -walk.weight

        walk = link

    self.paths.append(self.room_end.path)
    #
