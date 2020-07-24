/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 00:04:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			app_calc(t_app *self)
{
	t_option	*last;
	t_option	*best;

	self->paths = list_create();
	self->options = heap_create();
	self->ants = list_create();
	best = NULL;
	while (calc_bellman_ford(self))
	{
		calc_suurballe(self);
		last = calc_option(self);
		heap_insert(self->options, last->steps, last);
		best = heap_peek(self->options);
		if (best->steps < last->steps)
			break ;
	}
	if (best == NULL)
		app_error(self);
	ft_printf("#USE routes %d = %d steps\n", best->routes->count, best->steps);
	calc_populate(self, best->routes);
}
