/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:14:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 01:30:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_list	*calc_option_route(t_app *self, t_room *walk)
{
	t_list		*route;

	route = list_create();
	list_push_front(route, self->room_end);
	while (walk)
	{
		list_push_front(route, walk);
		walk = walk->path;
	}
	return (route);
}

static inline void		calc_option_routes(t_app *self, t_option *option)
{
	t_list_iter	*iter;
	t_room		*walk;
	t_list		*route;

	iter = list_iter_create(self->paths);
	while (list_iter_next(iter, (void **)&walk))
	{
		route = calc_option_route(self, walk);
		heap_insert(option->routes, route->count, route);
	}
	list_iter_destroy(&iter);
}

static inline void		calc_option_steps(t_app *self, t_option *option)
{
	t_heap		*heap;
	size_t		size;
	int			number;

	option->steps = 0;
	number = 0;
	heap = heap_copy(option->routes);
	while (number++ < self->number)
	{
		if (!heap_extract(heap, &size, NULL))
		{
			heap_destroy(&heap);
			app_error(self);
		}
		size++;
		if (option->steps < size - 2)
			option->steps = size - 2;
		heap_insert(heap, size, NULL);
	}
	heap_destroy(&heap);
}

t_option				*calc_option(t_app *self)
{
	t_option	*option;

	option = option_create();
	calc_option_routes(self, option);
	calc_option_steps(self, option);
	return (option);
}
