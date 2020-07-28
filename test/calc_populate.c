/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_populate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 02:18:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*list_from_heap(t_heap *heap)
{
	t_list	*list;
	t_heap	*copy;
	void	*data;

	list = list_create();
	copy = heap_copy(heap);
	while (heap_extract(copy, NULL, &data))
	{
		list_push_back(list, data);
	}
	heap_destroy(&copy);
	return (list);
}

void			calc_populate(t_app *self, t_option *option)
{
	int			number;
	size_t		steps;
	t_list		*list;
	t_list_iter	*iter;
	t_list		*route;

	number = 0;
	steps = option->steps;
	list = list_from_heap(option->routes);
	while (steps > 0)
	{
		iter = list_iter_create(list);
		while (list_iter_next(iter, (void **)&route))
		{
			if (steps > route->count - 2 && number < self->number)
				list_push_back(self->ants, (void *)ant_create(++number, route));
		}
		list_iter_destroy(&iter);
		steps--;
	}
	list_destroy(&list);
	if (number != self->number)
		app_error(self);
}
