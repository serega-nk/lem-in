/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 21:44:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_free(t_app *self)
{
	list_clean(self->ants, &ant_destroy);
	list_destroy(&self->ants);
	list_destroy(&self->paths);
	list_clean(self->links, &link_destroy);
	list_destroy(&self->links);
	hashtab_destroy(&self->pairs);
	hashtab_clean(self->rooms, &room_destroy);
	hashtab_destroy(&self->rooms);
	hashtab_destroy(&self->coords);
	list_clean(self->lines, &ft_strdel);
	list_destroy(&self->lines);
	gnl_destroy(&self->gnl);
}
