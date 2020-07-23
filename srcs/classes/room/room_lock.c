/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:15:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 21:40:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	room_lock(t_room *self)
{
	if (self->lock == TRUE)
		return (FALSE);
	self->lock = TRUE;
	return (TRUE);
}
