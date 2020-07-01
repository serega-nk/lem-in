/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_walk_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:07:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:17:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int		queue_walk_start(t_queue *self)
{
	if (self && self->size)
	{
		self->awalk = NULL;
		self->walk_remove = 0;
		return (1);
	}
	return (0);
}
