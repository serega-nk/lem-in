/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:23:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 09:08:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*deque_create(void)
{
	t_deque		*self;

	self = (t_deque *)ft_xmemalloc(sizeof(t_deque));
	return (self);
}
