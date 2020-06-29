/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:29:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 19:13:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

static void		resize(t_heap *self, t_heap_item *table, size_t size)
{
	self->size = size * 2;
	self->table = (t_heap_item *)ft_xmalloc(self->size * sizeof(t_heap_item));
	ft_memcmp(self->table, table, size);
	ft_memdel((void **)&table);
	ft_printf("RESIZE %llu => %llu\n", size, self->size);
}

void			heap_resize(t_heap *self)
{
	if (self && self->count == self->size)
		resize(self, self->table, self->size);
}
