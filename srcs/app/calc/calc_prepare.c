/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_prepare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:10:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 03:53:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		remove_links_between_subnodes(t_room *room)
{
	t_link	*walk;
	t_link	*link;

	hashtab_start(room->links);
	while (hashtab_next_kv(room->links, NULL, (void **)&walk))
	{
		hashtab_start(walk->room2->links);
		while (hashtab_next_kv(walk->room2->links, NULL, (void **)&link))
		{
			if (hashtab_get(link->room2->links, room->name, NULL))
			{
				link->remove = 1;
			}
		}
	}
}

void			calc_prepare(t_app *self)
{
	remove_links_between_subnodes(self->room_start);
	remove_links_between_subnodes(self->room_end);
}
