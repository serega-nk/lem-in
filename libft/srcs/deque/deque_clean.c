/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:23:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 09:12:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_clean(t_deque *self)
{
	t_deque_item	*item;

	if (self)
	{
		while (self->head)
		{
			item = self->head;
			self->head = item->next;
			deque_item_destroy(&item);
		}
		self->tail = NULL;
		self->size = 0;
	}
}
