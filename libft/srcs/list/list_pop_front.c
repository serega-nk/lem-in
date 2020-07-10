/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:23:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 14:24:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_pop_front(t_list *self, void **adata)
{
	t_list_item	*item;

	if (self && self->size > 0)
	{
		item = self->head;
		self->head = item->next;
		self->size--;
		if (self->size == 0)
			self->tail = NULL;
		if (adata)
			*adata = item->data;
		list_item_destroy(&item);
		return (1);
	}
	return (0);
}
