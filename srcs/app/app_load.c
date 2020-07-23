/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:47:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 21:44:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_load(t_app *self)
{
	self->gnl = gnl_create(STDIN_FILENO);
	self->lines = list_create();
	self->coords = hashtab_create();
	self->rooms = hashtab_create();
	self->pairs = hashtab_create();
	self->links = list_create();
	while (gnl_readline(self->gnl, &self->line) > 0)
	{
		list_push_back(self->lines, self->line);
		load_while(self);
	}
	load_check(self);
}
