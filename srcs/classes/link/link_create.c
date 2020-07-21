/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:25:07 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 05:03:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*link_create(t_room *room1, t_room *room2)
{
	t_link	*self;

	self = (t_link *)ft_xmemalloc(sizeof(t_link));
	self->type = LINK_EDGE;
	self->room1 = room1;
	self->room2 = room2;
	return (self);
}
