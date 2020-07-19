/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_excess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/19 07:54:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*calc_excess_route(t_app *self, t_room *walk)
{
	t_list		*route;

	route = list_create();
	list_push_front(route, self->room_end);
	while (walk)
	{
		if (walk->type != TYPE_OUT)
		{
			list_push_front(route, walk);
		}
		walk = walk->route;
	}
	return (route);
}

static t_heap	*calc_excess_routes(t_app *self)
{
	t_heap		*routes;
	t_list_iter	*iter;
	t_room		*walk;
	t_list		*route;

	routes = heap_create();
	iter = list_iter_create(self->paths);
	while (list_iter_next(iter, (void **)&walk))
	{
		route = calc_excess_route(self, walk);
		heap_insert(routes, route->size, route);
	}
	list_iter_destroy(&iter);
	return (routes);
}

static size_t	calc_excess_steps(t_app *self, t_heap *routes)
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

int				calc_excess(t_app *self)
{
	t_heap		*routes;
	size_t		steps;

	routes = calc_excess_routes(self);
	steps = calc_excess_steps(self, routes);
	ft_printf("# routes->count = %d, steps = %d\n", routes->count, steps);
	if (self->steps == 0 || self->steps > steps)
	{
		heap_clean(self->routes, &list_destroy);
		heap_destroy(&self->routes);
		self->routes = routes;
		self->steps = steps;
		return (0);
	}
	heap_clean(routes, &list_destroy);
	heap_destroy(&routes);
	ft_printf("# USE routes->count = %d, steps = %d\n", self->routes->count,  self->steps);
	return (1);
}
