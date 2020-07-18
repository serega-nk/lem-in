/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_populate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/19 00:54:35 by bconchit         ###   ########.fr       */
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

	ft_printf("# self->number = %d, self->routes->size = %d, longest_length = %d, total_length = %d\n", self->number, self->routes->size, self->longest_length, self->total_length);
	//capacity = (self->number + self->total_length + (int)self->routes->size - 1) / (int)self->routes->size;
	capacity = (self->total_length + self->number - 1) / (int)self->routes->size;
	ft_printf("# capacity = %d\n", capacity);
	number = 0;
	iter = list_iter_create(self->routes);
	//while (number < self->number && list_iter_next(iter, (void **)&route))
	while (list_iter_next(iter, (void **)&route))
	{

		count = capacity - ((int)route->size - 1);
		ft_printf("# capacity = %d, size = %d, count = %d, ants = %d\n", capacity, (int)route->size -1 , count, ft_min(count, self->number - number));
		while (number < self->number && count-- > 0)
			list_push_back(self->ants, (void *)ant_create(++number, route));
	}
	list_iter_destroy(&iter);
	if (number != self->number)
		app_error(self);
}
