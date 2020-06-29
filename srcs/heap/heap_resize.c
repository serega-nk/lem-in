/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:29:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:36:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

static void		resize(t_heap *self, t_heap_item *table, size_t size)
{
	ft_printf("#1\n");
	self->size = size * 2;
	self->table = (t_heap_item *)ft_xmalloc(self->size * sizeof(t_heap_item));
	ft_printf("=== RECREATE SIZE = %llu\n", self->size * sizeof(t_heap_item));
	ft_memcpy(self->table, table, size * sizeof(t_heap_item));
	ft_memdel((void **)&table);
	ft_printf("RESIZE %llu => %llu\n", size, self->size);
}

void			heap_resize(t_heap *self)
{
	ft_printf("S = %llu, C = %llu\n", self->size, self->count);
	if (self && self->count + 1 == self->size)
		resize(self, self->table, self->size);
}
