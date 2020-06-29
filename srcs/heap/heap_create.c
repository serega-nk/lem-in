/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:06:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:03:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_create(void)
{
	t_heap	*self;

	self = (t_heap *)ft_xmemalloc(sizeof(t_heap));
	self->size = 2;
	self->table = (t_heap_item *)ft_xmemalloc(self->size * sizeof(t_heap_item));
	return (self);
}
