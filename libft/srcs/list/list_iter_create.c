/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:00:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/09 21:00:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_iter		*list_iter_create(t_list *list)
{
	t_list_iter		*self;

	self = (t_list_iter *)ft_xmemalloc(sizeof(t_list_iter));
	self->list = list;
	return (self);
}
