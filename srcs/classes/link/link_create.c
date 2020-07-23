/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:25:07 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 21:19:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*link_create(t_part *part1, t_part *part2, int weight)
{
	t_link	*self;

	self = (t_link *)ft_xmemalloc(sizeof(t_link));
	self->part1 = part1;
	self->part2 = part2;
	self->weight = weight;
	return (self);
}
