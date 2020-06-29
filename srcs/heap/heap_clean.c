/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:14:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 19:38:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_clean(t_heap *self, void (*delf)())
{
	if (self)
	{
		if (delf)
			while (self->count > 0)
				(*delf)(&self->table[--self->count].data);
		self->count = 0;
	}
}
