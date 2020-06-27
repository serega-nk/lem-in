/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:52:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_room(t_app *self)
{
	if (self->signal_start && self->signal_end)
		app_error(self);
	self->signal_start = 0;
	self->signal_end = 0;
	//ft_printf("ROOM: %s", self->line);
	// check flags, none or one
	// save start end
	if (self)
		return (0);
	return (0);
}
