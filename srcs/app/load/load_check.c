/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:13:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 03:35:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_check(t_app *self)
{
	if (self->state != 2)
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (self->room_start == NULL || self->room_end == NULL)
		app_error(self);
}
