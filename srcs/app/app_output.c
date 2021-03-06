/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 23:14:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	output_lines(t_app *self)
{
	char	*line;

	while (list_pop_front(self->lines, (void **)&line))
	{
		ft_printf("%s", line);
		ft_strdel(&line);
	}
}

static inline void	output_steps(t_app *self)
{
	t_list_iter		*iter;
	t_ant			*ant;
	size_t			count;

	while (self->ants->count > 0)
	{
		count = 0;
		iter = list_iter_create(self->ants);
		while (list_iter_next(iter, (void **)&ant))
		{
			if (ant_move(ant))
			{
				if (count++)
					ft_printf(" ");
				ant_print(ant);
				if (ant_finish(ant))
					list_iter_remove(iter, &ant_destroy);
			}
		}
		ft_printf("\n");
		list_iter_destroy(&iter);
		if (count == 0)
			app_error(self);
	}
}

void				app_output(t_app *self)
{
	output_lines(self);
	ft_printf("\n");
	output_steps(self);
}
