/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 09:22:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 10:19:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_back(t_deque *self, void *data)
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
			item->prev = self->tail;
			item->prev->next = item;
			self->tail = item;
		}
		self->size++;
	}
}
