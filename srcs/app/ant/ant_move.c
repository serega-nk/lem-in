/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:31:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:32:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ant_move(t_ant *self)
{
	if (self && self->next && self->next->lock == 0)
	{
		if (self->curr)
			self->curr->lock = 0;
		self->curr = self->next;
		self->next = self->curr->path;
		if (self->next)
			self->curr->lock = 1;
		return (1);
	}
	return (0);
}
