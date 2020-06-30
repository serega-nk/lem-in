/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:14:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/28 05:23:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_while(t_app *self)
{
	if (load_signal(self))
		return ;
	if (load_comment(self))
		return ;
	if (self->state == 0)
	{
		load_number(self);
		self->state++;
		return ;
	}
	if (self->state == 1)
	{
		if (load_room(self))
			return ;
		self->state++;
	}
	load_link(self);
}
