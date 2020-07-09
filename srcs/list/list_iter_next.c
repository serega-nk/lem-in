/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:42:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/09 21:00:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_iter_next(t_list_iter *self, void **adata)
{
	if (self && self->list)
	{
		if (self->awalk == NULL)
			self->awalk = &self->list->head;
		else if (self->remove == 0)
			self->awalk = &(*self->awalk)->next;
		self->remove = 0;
		if (*self->awalk)
		{
			*adata = (*self->awalk)->data;
			return (1);
		}
	}
	return (0);
}
