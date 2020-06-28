/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/28 05:14:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_link_parse(char *line, t_link *link)
{
	if (parse_str(&line, &link->name1, "- \n") &&
		link->name1[0] != 'L' &&
		parse_skip(&line, "-") &&
		parse_str(&line, &link->name2, "- \n") &&
		link->name2[0] != 'L' &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
	{
		return (1);
	}
	return (0);
}

int			load_link(t_app *self)
{
	t_link	*link;

	if (self->signal_start || self->signal_end)
		app_error(self);
	link = link_create();
	if (load_link_parse(self->line, link))
	{
		queue_push_back(self->links, link);	
		return (1);
	}
	link_destroy(&link);
	app_error(self);
	return (0);
}
