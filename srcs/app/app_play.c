/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 06:40:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_play(t_app *self)
{
	//ft_printf_set_global_buffer(1024);
	while ((self->line = queue_pop_front(self->lines)))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
	ft_printf("\n");
	ft_printf("### PLAY\n");
	ft_printf("### ROOM START: %s, ROOM END: %s\n",
		self->room_start->name, self->room_end->name);
	//ft_printf_set_global_buffer(0);

	t_hashtab_item	*item;
	hashtab_start(self->room_start->links);
	while ((item = hashtab_next(self->room_start->links)))
	{
		//room = (t_room *)item->value;
		ft_printf("START: key = %s, room = %s\n", item->key, ((t_room *)item->value)->name);
	}

	t_room		*room;
	hashtab_start(self->room_end->links);
	while (hashtab_next_kv(self->room_end->links, NULL, (void **)&room))
	{
		ft_printf("END: link = %s\n", room->name);
	}

}
