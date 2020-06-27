/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:57:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_comment(t_app *self)
{
	if (ft_strcmp(self->line, "##start\n") == 0)
	{
		ft_printf("SIGNAL START\n");
		if (self->signal_start)
			app_error(self);
		self->signal_start = 1;
		return (1);
	}	
	if (ft_strcmp(self->line, "##end\n") == 0)
	{
		ft_printf("SIGNAL END\n");
		if (self->signal_end)
			app_error(self);
		self->signal_end = 1;
		return (1);
	}
	if (parse_skip(&self->line, "#"))
	{
		ft_printf("SKIP COMMENT\n");
		if (!parse_goto(&self->line, "\n"))
			app_error(self);
		if (!parse_none(&self->line))
			app_error(self);
		return (1);
	}
	return (0);
}
