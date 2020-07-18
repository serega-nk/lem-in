/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_populate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 05:49:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_populate(t_app *self)
{
	t_list_iter		*iter;
	t_list			*route;
	int				number;
	int				count;

	number = 0;
	iter = list_iter_create(self->routes);
	while (number < self->number && list_iter_next(iter, (void **)&route))
	{
		count = self->capacity - (int)route->size;
		while (number < self->number && count-- > 0)
			list_push_back(self->ants, (void *)ant_create(++number, route));
	}
	list_iter_destroy(&iter);
	if (number != self->number)
		app_error(self);
}
