/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:29:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:02:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

static void		resize(t_heap *self, t_heap_item *table, size_t size)
{
	self->size = size * 2;
	self->table = (t_heap_item *)ft_xmalloc(self->size * sizeof(t_heap_item));
	ft_memcpy(self->table, table, size * sizeof(t_heap_item));
	ft_memdel((void **)&table);
}

void			heap_resize(t_heap *self)
{
	if (self && self->count + 1 == self->size)
		resize(self, self->table, self->size);
}
