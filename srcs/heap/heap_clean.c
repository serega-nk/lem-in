/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:14:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:42:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_clean(t_heap *self, void (*delf)())
{
	if (self)
	{
		if (delf)
			while (self->count > 0)
			{
				ft_printf("DELETE %s\n", self->table[self->count - 1].data);
				(*delf)(&self->table[--self->count].data);
			}
		self->count = 0;
	}
}
