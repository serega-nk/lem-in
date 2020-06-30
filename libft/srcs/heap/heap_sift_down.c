/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sift_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:15:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:02:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_sift_down(t_heap *self, size_t index)
{
	size_t	curr;
	size_t	next;

	if (self)
	{
		curr = index;
		while (index < self->count)
		{
			next = 2 * index + 1;
			if (next < self->count &&
				self->table[next].priority < self->table[curr].priority)
				curr = next;
			next++;
			if (next < self->count &&
				self->table[next].priority < self->table[curr].priority)
				curr = next;
			if (index == curr)
				break ;
			heap_item_swap(&self->table[index], &self->table[curr]);
			index = curr;
		}
	}
}
