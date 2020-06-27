/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:13:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:56:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_check(t_app *self)
{
	ft_printf("CHECK STATE = %d\n", self->state);
	if (self->state != 2)
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	if (self->signal_start || self->signal_end)
		app_error(self);
	// if (self->room_start == NULL || self->room_end == NULL)
	// 	app_error(self);
}