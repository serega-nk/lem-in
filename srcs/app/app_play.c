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
	char	*line;

	if (self)
	{
		while ((line = queue_pop_front(self->lines)))
		{
			ft_printf("%s", line);
			ft_strdel(&line);
		}
		ft_printf("\n");
		ft_printf("PLAY\n");
	}
}
