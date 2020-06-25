/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:18:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 22:16:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_pop_front(t_queue *self)
{
	t_queue_item	*item;
	void			*data;

	data = NULL;
	if (self && self->size > 0)
	{
		self->size--;
		item = self->head;
		self->head = item->next;
		data = item->data;
		queue_item_destroy(&item);
		if (self->size == 0)
		{
			self->tail = NULL;
		}
	}
	return (data);
}
