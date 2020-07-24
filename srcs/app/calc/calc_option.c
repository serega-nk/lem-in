/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 19:14:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/24 23:43:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*calc_option_route(t_app *self, t_room *walk)
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

static t_heap	*calc_option_routes(t_app *self)
{
	t_heap		*routes;
	t_list_iter	*iter;
	t_room		*walk;
	t_list		*route;

	routes = heap_create();
	iter = list_iter_create(self->paths);
	while (list_iter_next(iter, (void **)&walk))
	{
		route = calc_option_route(self, walk);
		heap_insert(routes, route->count, route);
	}
	return (routes);
}

static size_t	calc_option_steps(t_app *self, t_heap *routes)
{
	t_heap		*heap;
	size_t		steps;
	size_t		size;
	int			number;

	steps = 0;
	number = 0;
	heap = heap_copy(routes);
	while (number++ < self->number)
	{
		if (!heap_extract(heap, &size, NULL))
		{
			heap_destroy(&heap);
			app_error(self);
		}
		size++;
		if (steps < size - 2)
			steps = size - 2;
		heap_insert(heap, size, NULL);
	}
	heap_destroy(&heap);
	return (steps);
}

t_option		*calc_option(t_app *self)
{
	t_option	*option;
	
	option = option_create();
	option->routes = calc_option_routes(self);
	option->steps = calc_option_steps(self, option->routes);
	return (option);
}
