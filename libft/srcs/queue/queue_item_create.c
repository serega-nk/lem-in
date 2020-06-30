/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_item_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:50:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 21:51:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue_item	*queue_item_create(void)
{
	t_queue_item		*self;

	self = (t_queue_item *)ft_xmemalloc(sizeof(t_queue_item));
	return (self);
}
