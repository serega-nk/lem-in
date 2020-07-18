/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_populate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 20:13:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_populate(t_app *self)
{
	t_list_iter		*iter;
	t_list			*route;
	int				number;
	int				count;
	int				capacity;

	ft_printf("# self->routes->size = %d, longest_length = %d, total_length = %d\n", self->routes->size, self->longest_length, self->total_length);


	capacity = (self->number + self->total_length + (int)self->routes->size - 1) / (int)self->routes->size;
	number = 0;
	iter = list_iter_create(self->routes);
	while (number < self->number && list_iter_next(iter, (void **)&route))
	{
		ft_printf("# size = %d\n", (int)route->size);
		count = capacity - (int)route->size;
		while (number < self->number && count-- > 0)
			list_push_back(self->ants, (void *)ant_create(++number, route));
	}
	list_iter_destroy(&iter);
	if (number != self->number)
		app_error(self);
}
