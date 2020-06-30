/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_item_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:32:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 08:33:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque_item	*deque_item_create(void)
{
	t_deque_item		*self;

	self = (t_deque_item *)ft_xmemalloc(sizeof(t_deque_item));
	return (self);
}
