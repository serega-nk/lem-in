/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:47:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 04:53:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_load(t_app *self)
{
	self->lines = list_create();
	self->rooms = hashtab_create();
	self->coords = hashtab_create();
	self->gnl = gnl_create(STDIN_FILENO);
	while (gnl_readline(self->gnl, &self->line) > 0)
	{
		list_push_back(self->lines, self->line);
		load_while(self);
	}
	load_check(self);
}
