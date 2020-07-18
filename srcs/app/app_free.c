/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 23:19:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_free(t_app *self)
{
	list_clean(self->ants, &ant_destroy);
	list_destroy(&self->ants);
	list_clean(self->routes, &list_destroy);
	list_destroy(&self->routes);
	list_destroy(&self->paths);
	list_clean(self->links, &link_destroy);
	list_destroy(&self->links);
	hashtab_clean(self->rooms, &room_destroy);
	hashtab_destroy(&self->rooms);
	hashtab_destroy(&self->coords);
	list_clean(self->lines, &ft_strdel);
	list_destroy(&self->lines);
	gnl_destroy(&self->gnl);
}
