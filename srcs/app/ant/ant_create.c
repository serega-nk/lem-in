/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:28:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 17:15:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ant_create(int id, t_list *route)
{
	t_ant	*self;

	self = (t_ant *)ft_xmemalloc(sizeof(t_ant));
	self->id = id; 
	self->walk = list_start(route);
	self->room = list_next(self->walk);
	self->next = list_next(self->walk);
	return (self);
}
