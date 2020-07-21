/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:15:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 17:54:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	room_lock(t_room *self)
{
	if (self->lock == 1)
		return (FALSE);
	self->lock = 1;
	return (TRUE);
}
