/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:22:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 14:22:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_push_back(t_list *self, void *data)
{
	t_list_item	*item;

	if (self)
	{
		item = list_item_create();
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
