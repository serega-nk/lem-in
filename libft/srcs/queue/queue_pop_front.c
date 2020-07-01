/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:18:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:48:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		queue_pop_front(t_queue *self, void **adata)
{
	t_queue_item	*item;

	if (self && self->size > 0)
	{
		item = self->head;
		self->head = item->next;
		self->size--;
		if (self->size == 0)
			self->tail = NULL;
		*adata = item->data;
		queue_item_destroy(&item);
		return (1);
	}
	return (0);
}
