/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:59:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_link_parse(t_link *link, char *line)
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
	if (!load_link_parse(link, self->line))
	{
		link_destroy(&link);
		app_error(self);
	}
	queue_push_back(self->links, link);	
	return (1);
}
