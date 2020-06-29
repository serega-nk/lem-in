/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:06:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 14:06:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

t_heap	*heap_create(void)
{
	t_heap	*self;

	self = (t_heap *)ft_xmemalloc(sizeof(t_heap));
	return (self);
}
