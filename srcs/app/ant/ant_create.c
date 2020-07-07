/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:28:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 22:12:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ant_create(int id, t_list *route)
{
	t_ant	*self;

	self = (t_ant *)ft_xmemalloc(sizeof(t_ant));
	self->id = id;
	self->iter = list_iter_create(route);
	self->room = list_iter_next2(self->iter);
	self->next = list_iter_next2(self->iter);
	return (self);
}
