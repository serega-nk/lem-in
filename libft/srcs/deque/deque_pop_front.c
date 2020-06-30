/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 09:22:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 10:26:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	*deque_pop_front(t_deque *self)
{
	t_deque_item	*item;
	void			*data;

	data = NULL;
	if (self && self->size > 0)
	{
		item = self->head;
		self->size--;
		if (self->size == 0)
		{
			self->head = NULL;
			self->tail = NULL;
		}
		else
		{
			self->head = item->next;
			self->head->prev = NULL;
		}
		data = item->data;
		deque_item_destroy(&item);
	}
	return (data);
}
