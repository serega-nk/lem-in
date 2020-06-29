/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:59:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:37:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

int		heap_extract(t_heap *self, size_t *apriority, void **adata)
{
	if (self && self->count > 0)
	{
		if (apriority)
			*apriority = self->table[0].priority;
		if (adata)
			*adata = self->table[0].data;
		self->count--;
		if (self->count > 0)
		{
			self->table[0].priority = self->table[self->count].priority;
			self->table[0].data = self->table[self->count].data;
			heap_sift_down(self, 0);
		}
		return (1);
	}
	return (0);
}
