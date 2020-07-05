/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:15:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 17:19:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_lock(t_room *self)
{
	// if (self->type == ROOM_END)
	// 	return (1);
	if (self->lock == 1)
		return (0);
	self->lock = 1;
	return (1);
}
