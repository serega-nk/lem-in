/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 23:09:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// t_list		*calc_route(t_app *self)
// {
// 	t_list *route;
// 	static int mode = 0;

// 	route = NULL;
// 	++mode;
// 	if (mode == 1)
// 	{
// 		t_room *r0, *r1, *r2, *r3, *r42, *r21;
// 		r0 = r42 = NULL;
// 		if (hashtab_get(self->rooms, "0", (void **)&r0) &&
// 			hashtab_get(self->rooms, "1", (void **)&r1) &&
// 			hashtab_get(self->rooms, "2", (void **)&r2) &&
// 			hashtab_get(self->rooms, "3", (void **)&r3) && 
// 			hashtab_get(self->rooms, "42", (void **)&r42) &&
// 			hashtab_get(self->rooms, "21", (void **)&r21))
// 		{
// 			ft_printf("111\n");
// 			route = list_create();
// 			list_push_back(route, r0);
// 			list_push_back(route, r1);
// 			list_push_back(route, r2);
// 			list_push_back(route, r3);
// 		}
// 	}
// 	if (mode == 2)
// 	{
// 		t_room *r0, *r1, *r2, *r3, *r42, *r21;
// 		r0 = r42 = NULL;
// 		if (hashtab_get(self->rooms, "0", (void **)&r0) &&
// 			hashtab_get(self->rooms, "1", (void **)&r1) &&
// 			hashtab_get(self->rooms, "2", (void **)&r2) &&
// 			hashtab_get(self->rooms, "3", (void **)&r3) && 
// 			hashtab_get(self->rooms, "42", (void **)&r42) &&
// 			hashtab_get(self->rooms, "21", (void **)&r21))
// 		{
// 			route = list_create();
// 			list_push_back(route, r42);
// 			list_push_back(route, r21);
// 			list_push_back(route, r3);
// 		}
// 	}
// 	return (route);
// }

// static int	calc_apply(t_app *self, t_list *route)
// {
// 	int		count;

// 	count = self->capacity - route->size;
// 	ft_printf("self->capacity = %d, route->size = %d\n", self->capacity, route->size);
// 	while (count-- > 0)
// 	{
// 		if (self->id_ant < self->number)
// 			list_push_back(self->ants, ant_create(++self->id_ant, route));
// 		if (self->id_ant >= self->number)
// 			return (LIST_FOREACH_STOP);
// 	}
// 	return (LIST_FOREACH_NEXT);	
// }

static int		calc_capacity(int number_ants, int number_route, int total_length)
{
	return ((number_ants + total_length + number_route - 1) / number_route);
}


static void		calc_populate(t_app *self, int capacity)
{
	t_list_iter		*iter;
	t_list			*route;
	int				id_ant;
	int				count;

	id_ant = 0;
	iter = list_iter_create(self->routes);
	while (id_ant < self->number && list_iter_next(iter, &route))
	{
		count = capacity - route->size;
		while (id_ant < self->number && count-- > 0)
			list_push_back(self->ants, ant_create(++id_ant, route));
	}
	list_iter_destroy(&iter);
	if (id_ant != self->number)	
		app_error(self);	
}

void			app_calc(t_app *self)
{
	// int		count;
	// int		length;
	// int		max_size;

	t_list			*route;
	t_list_iter		*iter;
	int				count;
	int				total_length;

	self->routes = list_create();
	self->ants = list_create();	
	
	if (self->routes->size == 0)
		app_error(self);
	
	int capacity;
	
	capacity = self->number + total_length + self->routes->size - 1;
	capacity /= self->routes->size;
	calc_populate(self, capacity);


	// count = 0;
	// length = 0;
	// max_size = 0;
	// while (count < self->number && (route = calc_route(self)))
	// {
	// 	list_push_back(self->routes, route);
	// 	ft_printf("route->size = %d\n", route->size);
	// 	length += route->size;
	// 	max_size = ft_max(max_size, route->size);
	// 	count = self->routes->size * (max_size + 1) - length;
	// }
	// if (self->routes->size == 0)
	// 	app_error(self);
	// self->capacity = (self->number + length + self->routes->size - 1);
	// self->capacity /= self->routes->size;
	// list_foreach(self->routes, &calc_apply, self);
}
