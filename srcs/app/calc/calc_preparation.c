/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:10:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 21:42:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		relative_link_remove(t_app *self, t_room *room)
{
	t_link	*link;
	t_link	*link2;

	if (self)
		;
	int	index = 0;
	hashtab_start(room->links);
	while (hashtab_next_kv(room->links, NULL, (void **)&link))
	{
		hashtab_start(link->room2->links);
		while (hashtab_next_kv(link->room2->links, NULL, (void **)&link2))
		{
			if (hashtab_get(link2->room2->links, room->name, NULL))
			{
				ft_printf("%s -> %s\n", link->room2->name, link2->room2->name);
				index += 1;
			}
		}
	}
	ft_printf("index = %d\n", index);
}

void			calc_preparation(t_app *self)
{
	relative_link_remove(self, self->room_start);
	relative_link_remove(self, self->room_end);
}

// for link in room.links.values():
// 	link_room = link.room2
// 	for name in room.links.keys():
// 		if name in link_room.links:
// 			self.links.remove(link_room.links[name])
// 			del link_room.links[name]
