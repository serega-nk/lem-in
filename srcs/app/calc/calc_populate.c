/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_populate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:04:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/19 07:03:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		calc_populate(t_app *self)
{
	int		number;
	size_t	size;
	t_list	*route;
	
	number = 0;
	while (number++ < self->number)
	{
		if (!heap_extract(self->routes, &size, (void **)&route))
		{
			app_error(self);
		}			
		list_push_back(self->ants, (void *)ant_create(number, route));
		heap_insert(self->routes, size + 1, (void *)route);		
	}
}
