/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_extract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:59:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:53:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_bool	heap_extract(t_heap *self, size_t *apriority, void **adata)
{
	if (self && self->count > 0)
	{
		self->count--;
		if (self->count > 0)
		{
			heap_item_swap(&self->table[0], &self->table[self->count]);
			heap_sift_down(self, 0);
		}
		if (apriority)
			*apriority = self->table[self->count].priority;
		if (adata)
			*adata = self->table[self->count].data;
		return (TRUE);
	}
	return (FALSE);
}
