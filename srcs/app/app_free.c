/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 14:56:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_free(t_app *self)
{
	//ft_printf("FREE\n");
	if (self->gnl)
		gnl_destroy(&self->gnl);
	if (self->lines)
	{
		while ((self->line = queue_pop_front(self->lines)))
			ft_strdel(&self->line);
		queue_destroy(&self->lines);
	}
}
