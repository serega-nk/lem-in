/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 05:23:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 17:56:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	load_signal(t_app *self)
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
		self->signal_start = TRUE;
		return (TRUE);
	}
	if (ft_strcmp(self->line, "##end\n") == 0)
	{
		if (self->signal_end)
			app_error(self);
		self->signal_end = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
