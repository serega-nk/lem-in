/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <jremarqu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 00:55:11 by jremarqu          #+#    #+#             */
/*   Updated: 2020/07/11 00:55:22 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// def bfs(starting_room):
//     starting_room.level = 1
//     order = []
//     order.append(starting_room)
//     while order:
//         room = order.pop(0)
//         for r in room.links:
//             if r.level == 0:
//                 r.level = room.level + 1
//                 order.append(r)

void	room_unlink(t_room *room1, t_room *room2)
{
	// if (self->room_start == room1 || self->room_start == room2 || self->room_end == room1 || self->room_end == room2)
	// 	return ;
	ft_printf("UNLINK %s -- %s\n", room1->name, room2->name);
	hashtab_remove(room1->links, room2->name, NULL);
	hashtab_remove(room2->links, room1->name, NULL);
}


void	app_bfs_algo(t_app *self)
{
	t_list	*order;
	t_room	*room;
	t_room	*link_room;

	order = list_create();
	self->room_start->level = 1;
	list_push_back(order, self->room_start);

	// if (hashtab_get(self->rooms, "r2", (void **)&link_room))
	// {
	// 	room_unlink(self->room_start, link_room);
	// }	
	// if (hashtab_get(self->rooms, "r1", (void **)&link_room))
	// {
	// 	room_unlink(self->room_start, link_room);
	// }	

	while (list_pop_front(order, (void **)&room))
	{
		// ft_printf("room = %s\n", room->name);
		hashtab_start(room->links);
		while (hashtab_next_kv(room->links, NULL, (void **)&link_room))
		{
			if (link_room->level == 0)
			{
				link_room->level = room->level + 1;
				link_room->path = room;
				list_push_back(order, link_room);
			}	
		}
	}
	// ft_printf("end level = %d\n", self->room_end->level);
}

t_list	*test(t_app *self)
{
	t_room	*room;
	t_list	*route;
	t_room			*link_room;

	route = list_create();
	room = self->room_end;
	while (room)
	{
		
		// ft_printf("TEST %s (%d)\n", room->name, room->level);
		hashtab_start(room->links);
		while (hashtab_next_kv(room->links, NULL, (void **)&link_room))
		{
			if (room != self->room_start && room != self->room_end)
				room_unlink(room, link_room);
		}

		list_push_front(route, room);
		room = room->path;
	}
	if (route->size == 0)
		list_destroy(&route);
	return (route);
}

static t_list	*calc_route(t_app *self)
{
	t_list *route;
	static int mode = 0;

	route = NULL;
	++mode;
	if (mode == 1)
	{
		app_bfs_algo(self);
		route = test(self);
		// t_room *r0, *r1, *r2, *r3, *r42, *r21;
		// r0 = r42 = NULL;
		// if (hashtab_get(self->rooms, "0", (void **)&r0) &&
		// 	hashtab_get(self->rooms, "1", (void **)&r1) &&
		// 	hashtab_get(self->rooms, "2", (void **)&r2) &&
		// 	hashtab_get(self->rooms, "3", (void **)&r3) &&
		// 	hashtab_get(self->rooms, "42", (void **)&r42) &&
		// 	hashtab_get(self->rooms, "21", (void **)&r21))
		// {
		// 	route = list_create();
		// 	list_push_back(route, r0);
		// 	list_push_back(route, r1);
		// 	list_push_back(route, r2);
		// 	list_push_back(route, r3);
		// }
	}
	if (mode == 2)
	{
		t_room	*room;
		hashtab_start(self->rooms);
		while (hashtab_next_kv(self->rooms, NULL, (void **)&room))
		{
			room->level = 0;
			room->path = NULL;
		}
		app_bfs_algo(self);
		route = test(self);

	// 	t_room *r0, *r1, *r2, *r3, *r42, *r21;
	// 	r0 = r42 = NULL;
	// 	if (hashtab_get(self->rooms, "0", (void **)&r0) &&
	// 		hashtab_get(self->rooms, "1", (void **)&r1) &&
	// 		hashtab_get(self->rooms, "2", (void **)&r2) &&
	// 		hashtab_get(self->rooms, "3", (void **)&r3) &&
	// 		hashtab_get(self->rooms, "42", (void **)&r42) &&
	// 		hashtab_get(self->rooms, "21", (void **)&r21))
	// 	{
	// 		route = list_create();
	// 		list_push_back(route, r42);
	// 		list_push_back(route, r21);
	// 		list_push_back(route, r3);
	// 	}
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
