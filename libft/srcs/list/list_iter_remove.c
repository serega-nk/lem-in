/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:51:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 21:55:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_iter_remove(t_list_iter *self, void (*delf)())
{
	t_list_item		*item;

	if (self && self->list && self->list > 0 && self->awalk && *self->awalk)
	{
		item = *self->awalk;
		*self->awalk = (*self->awalk)->next;
		self->list->size--;
		if (delf)
			(*delf)(&item->data);
		list_item_destroy(&item);
		self->remove = 1;
		return (1);
	}
	return (0);
}
