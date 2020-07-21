/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:23:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 14:07:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_pop_front(t_list *self, void **adata)
{
	t_list_item	*item;

	if (self && self->count > 0)
	{
		item = self->head;
		self->head = item->next;
		self->count--;
		if (self->count == 0)
			self->tail = NULL;
		if (adata)
			*adata = item->data;
		list_item_destroy(&item);
		return (1);
	}
	return (0);
}
