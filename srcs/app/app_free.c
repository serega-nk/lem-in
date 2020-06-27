/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 14:24:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lines_destroy(t_queue **addr)
{
	char	*line;

	while ((line = queue_pop_front(*addr)))
		ft_strdel(&line);
	queue_destroy(addr);
}

void			app_free(t_app *self)
{
	if (self)
	{
		//ft_printf("FREE\n");
		if (self->gnl)
			gnl_destroy(&self->gnl);
		if (self->lines)
			lines_destroy(&self->lines);
	}
}
