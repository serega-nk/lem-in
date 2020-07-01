/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_walk_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:07:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/01 22:24:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		queue_walk_next(t_queue *self, void **adata)
{
	if (self && self->size)
	{
		if (self->awalk)
		{

		}
		else
		{
			/* code */
		}
		
		
		{
			self->walk_prev = self->walk;

			if (self->walk)
				self->walk = self->walk->next;
			else
				self->walk = self->head;
			
			
		if ((self->walk_next = self->head))
			return (1);
	}
	return (0);
}
