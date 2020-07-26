/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:51:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:44:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_bool	list_iter_remove(t_list_iter *self, void (*delf)())
{
	t_list_item		*item;

	if (self && self->list && self->list->count && self->awalk && *self->awalk)
	{
		item = *self->awalk;
		*self->awalk = (*self->awalk)->next;
		self->list->count--;
		if (delf)
			(*delf)(&item->data);
		list_item_destroy(&item);
		self->remove = TRUE;
		return (TRUE);
	}
	return (FALSE);
}
