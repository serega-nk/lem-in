/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 05:58:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 18:03:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*room_create(void)
{
	t_room	*self;

	self = (t_room *)ft_xmemalloc(sizeof(t_room));
	self->type = TYPE_ROOM;
	self->links = hashtab_create();
	return (self);
}
