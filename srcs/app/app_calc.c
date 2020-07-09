/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/09 22:49:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*calc_route(t_app *self)
{
	t_list *route;
	static int mode = 0;

	route = NULL;
	++mode;
	if (mode == 1)
	{
		t_room *r0, *r1, *r2, *r3, *r42, *r21;
		r0 = r42 = NULL;
		if (hashtab_get(self->rooms, "0", (void **)&r0) &&
			hashtab_get(self->rooms, "1", (void **)&r1) &&
			hashtab_get(self->rooms, "2", (void **)&r2) &&
			hashtab_get(self->rooms, "3", (void **)&r3) &&
			hashtab_get(self->rooms, "42", (void **)&r42) &&
			hashtab_get(self->rooms, "21", (void **)&r21))
		{
			route = list_create();
			list_push_back(route, r0);
			list_push_back(route, r1);
			list_push_back(route, r2);
			list_push_back(route, r3);
		}
	}
	if (mode == 2)
	{
		t_room *r0, *r1, *r2, *r3, *r42, *r21;
		r0 = r42 = NULL;
		if (hashtab_get(self->rooms, "0", (void **)&r0) &&
			hashtab_get(self->rooms, "1", (void **)&r1) &&
			hashtab_get(self->rooms, "2", (void **)&r2) &&
			hashtab_get(self->rooms, "3", (void **)&r3) &&
			hashtab_get(self->rooms, "42", (void **)&r42) &&
			hashtab_get(self->rooms, "21", (void **)&r21))
		{
			route = list_create();
			list_push_back(route, r42);
			list_push_back(route, r21);
			list_push_back(route, r3);
		}
	}
	return (route);
}

static void		calc_routes(t_app *self)
{
	t_list		*route;
	int			effective_amount;
	int			total_length;
	int			max_length;

	self->routes = list_create();
	effective_amount = 0;
	total_length = 0;
	max_length = 0;
	while (effective_amount < self->number && (route = calc_route(self)))
	{
		list_push_back(self->routes, route);
		total_length += route->size;
		max_length = ft_max(max_length, route->size);
		effective_amount = self->routes->size * (max_length + 1) - total_length;
	}
	if (self->routes->size == 0)
		app_error(self);
	self->capacity = self->number + total_length + self->routes->size - 1;
	self->capacity /= self->routes->size;
}

static void		calc_ants(t_app *self)
{
	t_list_iter		*iter;
	t_list			*route;
	int				number;
	int				count;

	self->ants = list_create();
	number = 0;
	iter = list_iter_create(self->routes);
	while (number < self->number && list_iter_next(iter, (void **)&route))
	{
		count = self->capacity - route->size;
		while (number < self->number && count-- > 0)
			list_push_back(self->ants, (void *)ant_create(++number, route));
	}
	list_iter_destroy(&iter);
	if (number != self->number)
		app_error(self);
}

void			app_calc(t_app *self)
{
	calc_routes(self);
	calc_ants(self);
}
