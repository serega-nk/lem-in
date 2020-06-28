/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:16:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 21:47:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*queue_create(void)
{
	t_queue		*self;

	self = (t_queue *)ft_xmemalloc(sizeof(t_queue));
	return (self);
}
