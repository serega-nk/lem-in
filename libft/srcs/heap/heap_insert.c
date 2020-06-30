/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:42:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:07:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_insert(t_heap *self, size_t priority, void *data)
{
	size_t	index;

	if (self)
	{
		index = self->count++;
		heap_resize(self);
		self->table[index].priority = priority;
		self->table[index].data = data;
		heap_sift_up(self, index);
	}
}
