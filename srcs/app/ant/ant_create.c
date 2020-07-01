/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:28:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:30:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ant_create(int id, t_room *first)
{
	t_ant	*self;

	self = (t_ant *)ft_xmemalloc(sizeof(t_ant));
	self->id = id;
	self->curr = NULL;
	self->next = first;
	return (self);
}
