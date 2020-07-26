/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 06:38:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/27 00:27:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap		*heap_copy(t_heap *heap)
{
	t_heap	*self;

	if (heap)
	{
		self = (t_heap *)ft_xmemalloc(sizeof(t_heap));
		self->size = heap->size;
		self->count = heap->count;
		self->table = (t_heap_item *)
			ft_xmalloc(self->size * sizeof(t_heap_item));
		ft_memcpy(self->table, heap->table, self->size * sizeof(t_heap_item));
		return (self);
	}
	return (NULL);
}
