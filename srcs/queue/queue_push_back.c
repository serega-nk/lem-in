/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:19:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 22:08:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_push_back(t_queue *self, void *data)
{
	t_queue_item	*item;

	if (self)
	{
		item = queue_item_create();
		item->data = data;
		if (self->size == 0)
		{
			self->head = item;
			self->tail = item;
		}
		else
		{
			self->tail->next = item;
			self->tail = item;
		}
		self->size++;
	}
}
