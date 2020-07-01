/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_walk_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:07:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:35:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		queue_walk_remove(t_queue *self, void (*delf)())
{
	t_queue_item	*item;

	if (self && self->size && self->awalk)
	{
		item = *self->awalk;
		*self->awalk = (*self->awalk)->next;
		self->size--;
		if (delf)
			(*delf)(&item->data);
		queue_item_destroy(&item);
		self->walk_remove = 1;
		return (1);
	}
	return (0);
}
