/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 00:00:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 05:26:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_calc(t_app *self)
{
	int		poss;

	calc_prepare(self);
	poss = ft_min(self->room_start->links->count, self->room_end->links->count);
	while (poss-- > 0)
	{
		if (!calc_bellman_ford(self))
			break ;		
		calc_suurballe(self);
		if (calc_excess(self))
			break ;
	}
	calc_populate(self);
}
