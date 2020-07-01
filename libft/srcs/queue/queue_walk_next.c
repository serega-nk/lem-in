/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_walk_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:07:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:11:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "ft_printf.h"

int		queue_walk_next(t_queue *self, void **adata)
{
	if (self && self->size)
	{
		if (self->awalk == NULL)
			self->awalk = &self->head;
		else if (self->walk_remove == 0)
			self->awalk = &(*self->awalk)->next;
		self->walk_remove = 0;
		if (*self->awalk)
		{
			*adata = (*self->awalk)->data;
			return (1);
		}
	}
	return (0);
}
