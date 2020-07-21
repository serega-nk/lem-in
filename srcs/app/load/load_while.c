/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:14:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 18:06:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_while(t_app *self)
{
	if (load_signal(self))
		return ;
	if (load_comment(self))
		return ;
	if (self->state == LOAD_NUMBER)
	{
		load_number(self);
		self->state = LOAD_ROOM;
		return ;
	}
	if (self->state == LOAD_ROOM)
	{
		if (load_room(self))
			return ;
		self->state = LOAD_LINK;
	}
	load_link(self);
}
