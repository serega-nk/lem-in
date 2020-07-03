/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 01:23:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*get_route(t_app *self)
{

}

// int		func2(t_app *self, t_queue *route, int count)
// {
	
// }

// int		func1(t_app *self, int count)
// {
// 	t_queue		*route;
// 	int			index;

// 	queue_start(self->routes);
// 	while (self->number > 0 && queue_next(self->routes, &route))
// 	{
// 		index = count;
// 		while (self->number > 0 && index-- > 0)
// 			queue_push_back(self->ants, ant_create(self->number--, route));
// 	}
// 	return (self->number > self->ants->size);
// }

// void	app_calc___(t_app *self)
// {
// 	t_queue		*route;
// 	t_queue		*last;

// 	last = get_route(self);
// 	if (!last)
// 		app_error(self);
// 	if (self->number > 0)
// 		queue_push_back(self->ants, ant_create(self->number--, last));
// 	queue_push_back(self->routes, last);
// 	while (self->number > 0 && (route = get_route(self)))
// 	{
// 		queue_push_back(self->ants, ant_create(self->number--, route));
// 		func1(self, route->size - last->size);
// 		queue_push_back(self->routes, route);
// 	}
// 	if (self->number > 0)
// 		func1(self, 1 + (self->number / self->routes->size));
// 	if (self->number != 0)
// 		app_error(self);
	
// }

// int		add_ant(t_app *self, t_queue *route)
// {
// 	if (self->number > 0)
// 		queue_push_back(self->ants, ant_create(self->number--, route));
			
// 	return (0);

// }

// void	antfarm_is_full()
// {

// }

// void			calc_add_route(t_app *self, t_queue *route)
// {

// }

// static int		calc_is_maximum(t_app *self)
// {
// 	return (self->ant_id == self->number);
// }

// static void		calc_complete(t_app *self)
// {
// 	t_queue		*route;

// 	if (calc_is_maximum(self))
// 		return ;
// 	while (queue_start(self->routes))
// 	{
// 		while (queue_next(self->routes, (void **)&route))
// 		{
// 			if (calc_is_maximum(self))
// 				return ;
// 			queue_push_back(self->ants, ant_create(++self->ant_id, route));
// 		}
// 	}
// 	app_error(self);


// 			if (ant_move(ant))
// 			{
// 				ant_print(ant, count++);
// 				if (ant_finish(ant))
// 					queue_remove(self->ants, &ant_destroy);
// 			}
// 		}
// 		ft_printf("\n");
// 		if (count == 0)
// 			app_error(self);
// 	}


// 	// int		count_ants;
// 	// int		count_routes;
// 	// int		count;

// 	// count_ants = self->number - self->ant_id;
// 	// count_routes = self->routes->size;
// 	// if (count_ants > 0 && count_routes > 0)
// 	// {
// 	// 	part = (count_ants + count_routes - 1) / count_routes;
// 	// 	ants_populate(self, self->number - self->ant_id);
// 	// }	 
// }

static int		calc_add_ants_all_routes(t_app *self, int count)
{
	t_queue		*route;

	while (queue_start(self->routes))
	{
		while (queue_next(self->routes, (void **)&route))
		{
			if (!calc_add_ants_route(self, route, count))
				return (0);
		}
	}
	return (1);
}

static int		calc_add_ants_route(t_app *self, t_queue *route, int count)
{
	
}


static int		calc_while(t_app *self)
{
	t_queue		*route;

	if (antfarm_full(self))
		return ;
	route = get_route(self);
	if (route)
	{
		if (self->last_route)
			ants_add_all_routes(self, route->size - self->last_route->size);
		queue_push_back(self->routes, route);
		ants_add_route(self, route, 1);
		self->last_route = route;
	}
}

static void		calc_complete(t_app *self)
{
	t_queue		*route;

	while (queue_start(self->routes))
	{
		while (queue_next(self->routes, (void **)&route))
		{
			if (!calc_add_ant(self, route, 1))
				return ;
		}
	}
	app_error(self);
}

void			app_calc(t_app *self)
{
	t_queue		*route;
	t_queue		*last;

	route = get_route(self);
	while (route)
	{
		if (last)
			antfarm_add(self, route->size - self->last_route->size);
		
		last = route;
		route = get_route(self);
	}
	

	while (calc_while(self))
		;
	calc_complete(self);
}


	// t_queue		*last;

	// last = get_route(self);
	// if (!last)
	// 	app_error(self);
	// if (self->number > 0)
	// 	queue_push_back(self->ants, ant_create(self->number--, last));
	// queue_push_back(self->routes, last);
	// while (self->number > 0 && (route = get_route(self)))
	// {
	// 	queue_push_back(self->ants, ant_create(self->number--, route));
	// 	func1(self, route->size - last->size);
	// 	queue_push_back(self->routes, route);
	// }
	// if (self->number > 0)
	// 	func1(self, 1 + (self->number / self->routes->size));
	// if (self->number != 0)
	// 	app_error(self);
	// if (self)
	// {
	// 	ft_printf("### CALC\n");

	// 	t_room *r0, *r1, *r2, *r3, *r42, *r21;
	// 	r0 = r42 = NULL;
	// 	if (hashtab_get(self->rooms, "0", (void **)&r0) &&
	// 		hashtab_get(self->rooms, "1", (void **)&r1) &&
	// 		hashtab_get(self->rooms, "2", (void **)&r2) &&
	// 		hashtab_get(self->rooms, "3", (void **)&r3) && 
	// 		hashtab_get(self->rooms, "42", (void **)&r42) &&
	// 		hashtab_get(self->rooms, "21", (void **)&r21))
	// 	{
	// 		r0->path = r1;
	// 		r1->path = r2;
	// 		r2->path = r3;
	// 		r42->path = r21;
	// 		r21->path = r3;
	// 	}
	// 	self->ants = queue_create();
	// 	while (self->number)
	// 	{
	// 		if (self->number)
	// 			queue_push_back(self->ants, ant_create(self->number--, r0));
	// 		if (self->number)
	// 			queue_push_back(self->ants, ant_create(self->number--, r42));
	// 	}

	// }
// }
