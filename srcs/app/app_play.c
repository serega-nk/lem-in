/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 00:01:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_play(t_app *self)
{
	//ft_printf_set_global_buffer(1024);
	while ((self->line = queue_pop_front(self->lines)))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
	ft_printf("\n");
	ft_printf("PLAY\n");
	//ft_printf_set_global_buffer(0);
}
