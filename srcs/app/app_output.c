/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 17:28:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		output_lines(t_app *self)
{
	while (list_pop_front(self->lines, (void **)&self->line))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
}

static int		output_foreach(t_app *self, t_ant *ant)
{
	if (ant_move(ant))
	{
		if (self->count++)
			ft_printf(" ");
		ant_print(ant);
		if (ant_finish(ant))
		{
			ant_destroy(&ant);
			return (LIST_FOREACH_REMOVE);
		}
	}
	return (LIST_FOREACH_NEXT);
}

static void		output_steps(t_app *self)
{
	ft_printf("self->ants->size = %d\n", self->ants->size);
	while (self->ants->size)
	{
		self->count = 0;
		list_foreach(self->ants, &output_foreach, self);
		
		if (self->count == 0)
			app_error(self);
		ft_printf("\n");
	}
}

void			app_output(t_app *self)
{
	output_lines(self);
	ft_printf("\n");
	output_steps(self);
}
