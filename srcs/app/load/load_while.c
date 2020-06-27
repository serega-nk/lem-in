/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:14:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:47:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_while(t_app *self)
{
	ft_printf(self->line);
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
