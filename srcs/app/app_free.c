/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:18:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			app_free(t_app *self)
{
	gnl_destroy(&self->gnl);
	hashtab_destroy(&self->coords);
	hashtab_clean(self->rooms, &room_destroy);
	hashtab_destroy(&self->rooms);
	queue_clean(self->lines, &ft_strdel);
	queue_destroy(&self->lines);
}
