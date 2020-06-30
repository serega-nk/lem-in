/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sift_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:14:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:07:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_sift_up(t_heap *self, size_t index)
{
	size_t	parent;

	if (self)
	{
		while (index > 0)
		{
			parent = (index - 1) / 2;
			if (self->table[parent].priority <= self->table[index].priority)
				break ;
			heap_item_swap(&self->table[parent], &self->table[index]);
			index = parent;
		}
	}
}
