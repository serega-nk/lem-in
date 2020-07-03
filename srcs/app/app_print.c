/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/03 19:34:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_lines(t_app *self)
{
	while (queue_pop_front(self->lines, (void **)&self->line))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
}

static void		print_steps_ants(t_app *self)
{
	t_ant	*ant;
	int		count;

	while (queue_start(self->ants))
	{
		count = 0;
		while (queue_next(self->ants, (void **)&ant))
		{
			if (ant_move(ant))
			{
				ant_output(ant, count++);
				if (ant_finish(ant))
					queue_remove(self->ants, &ant_destroy);
			}
		}
		ft_printf("\n");
		if (count == 0)
			app_error(self);
	}
}

void			app_print(t_app *self)
{
	print_lines(self);
	ft_printf("\n");
	print_steps_ants(self);
}
