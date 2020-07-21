/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 05:25:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 05:27:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_reset(t_room *self)
{
	self->in.link = NULL;
	self->in.level = 0;
	self->out.link = NULL;
	self->out.level = 0;
}
