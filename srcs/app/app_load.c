/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:47:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:31:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_load(t_app *self)
{
	self->lines = queue_create();
	self->rooms = queue_create();
	self->links = queue_create();
	self->gnl = gnl_create(STDIN_FILENO);
	while (gnl_readline(self->gnl, &self->line) > 0)
	{
		queue_push_back(self->lines, self->line);
		load_while(self);
	}
	load_check(self);
}
