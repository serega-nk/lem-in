/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:13:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 18:22:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_final(t_app *self)
{
	if (self->state != 2)
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (self->room_start == NULL || self->room_end == NULL)
		app_error(self);
	self->room_start->type = TYPE_START;
	self->room_end->type = TYPE_END;
}
