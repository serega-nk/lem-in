/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 20:45:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			app_calc(t_app *self)
{
	t_option	*option;

	self->paths = list_create();
	self->options = heap_create();
	self->ants = list_create();
	// int i = 0;
	while (calc_shortest(self))
	{
		calc_disjoint(self);
		option = calc_option(self);
		ft_printf("# routes %d = %d steps\n", option->routes->count, option->steps);
		heap_insert(self->options, option->steps, option);
		// i++;
		// if (i > 2)
		// 	break ;
	}
	if (self->options->count == 0)
		app_error(self);
	option = (t_option *)self->options->table->data;
	ft_printf("## routes %d = %d steps\n", option->routes->count, option->steps);

	// t_heap	*heap;
	// t_list	*route;

	// heap = heap_copy(option->routes);
	// while (heap_extract(heap, NULL, (void **)&route))
	// {
	// 	ft_printf("# %d = [", route->count);
		
	// 	t_list_iter	*iter;
	// 	t_room		*room;
	// 	int 		count;
		
	// 	count = 0;
	// 	iter = list_iter_create(route);
	// 	while (list_iter_next(iter, (void **)&room))
	// 	{
	// 		if (count > 0)
	// 			ft_printf(", ");
	// 		ft_printf("\"%s\"", room->name);
	// 		count += 1;
	// 	}
	// 	ft_printf("]\n");
	// }
	calc_populate(self, option->routes);
	//app_error(self);
}
