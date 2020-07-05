/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 04:54:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_free(t_app *self)
{
	queue_clean(self->ants, &ant_destroy);
	queue_destroy(&self->ants);
	ft_strdel(&self->key);
	gnl_destroy(&self->gnl);
	hashtab_destroy(&self->coords);
	hashtab_clean(self->rooms, &room_destroy);
	hashtab_destroy(&self->rooms);
	list_clean(self->lines, &ft_strdel);
	list_destroy(&self->lines);
}
