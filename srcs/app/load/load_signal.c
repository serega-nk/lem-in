/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 05:23:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/11 22:38:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_signal(t_app *self)
{
	if (self->signal_start || self->signal_end)
	{
		if (ft_strncmp(self->line, "##", 2) == 0)
			app_error(self);
	}
	if (ft_strcmp(self->line, "##start\n") == 0)
	{
		if (self->signal_start)
			app_error(self);
		self->signal_start = 1;
		return (1);
	}
	if (ft_strcmp(self->line, "##end\n") == 0)
	{
		if (self->signal_end)
			app_error(self);
		self->signal_end = 1;
		return (1);
	}
	return (0);
}
