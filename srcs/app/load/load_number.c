/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:16:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 05:19:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_number_parse(t_app *self)
{
	char	*line;

	line = self->line;
	if (parse_int(&line, &self->number) &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
		return (1);
	return (0);
}

int			load_number(t_app *self)
{
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (!load_number_parse(self))
		app_error(self);
	if (self->number <= 0)
		app_error(self);
	return (1);
}
