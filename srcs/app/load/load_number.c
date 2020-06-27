/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:16:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:48:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_number(t_app *self)
{
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (!parse_int(&self->line, &self->number))
		app_error(self);
	if (!parse_skip(&self->line, "\n"))
		app_error(self);
	if (!parse_none(&self->line))
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	return (1);
}
