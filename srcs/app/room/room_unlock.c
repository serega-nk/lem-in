/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:15:58 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/09 20:12:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_unlock(t_room *self)
{
	if (self)
		self->lock = 0;
}