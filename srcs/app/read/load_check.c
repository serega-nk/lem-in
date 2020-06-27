/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:13:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 04:13:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_check(t_app *self)
{
	if (self->state != 2)
		app_error(self);
	if (self->number_of_ants <= 0)
		app_error(self);
	if (self->flag_start || self->flag_end)
		app_error(self);
	if (self->room_start == NULL || self->room_end == NULL)
		app_error(self);
}
