/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 09:06:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 10:19:40 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_front(t_deque *self, void *data)
{
	t_deque_item	*item;

	if (self)
	{
		item = deque_item_create();
		item->data = data;
		if (self->size == 0)
		{
			self->head = item;
			self->tail = item;
		}
		else
		{
			item->next = self->head;
			item->next->prev = item;
			self->head = item;
		}
		self->size++;
	}
}
