/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:31:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/09 22:39:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_move(t_ant *self)
{
	if (self)
	{
		if (room_lock(self->next))
		{
			room_unlock(self->room);
			self->room = self->next;
			self->next = (t_room *)list_iter_next2(self->iter);
			if (!self->next)
				room_unlock(self->room);
			return (1);
		}
	}
	return (0);
}
