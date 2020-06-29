/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 05:39:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_link_parse(t_app *self, char **aname1, char **aname2)
{
	char	*line;

	line = self->line;
	if (parse_str(&line, aname1, "- \n") &&
		*(*aname1) != 'L' &&
		parse_skip(&line, "-") &&
		parse_str(&line, aname2, "- \n") &&
		*(*aname2)!= 'L' &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
	{
		return (1);
	}
	return (0);
}

int			load_link(t_app *self)
{
	char	*name1;
	char	*name2;
	t_room	*room1;
	t_room	*room2;

	if (self->signal_start || self->signal_end)
		app_error(self);
	if (!load_link_parse(self, &name1, &name2) ||
		!hashtab_get(self->rooms, name1, (void **)&room1) ||
		!hashtab_get(self->rooms, name2, (void **)&room2) ||
		!hashtab_insert(room1->links, name2, room2) ||
		!hashtab_insert(room2->links, name1, room1))
	{
		ft_strdel(&name2);
		ft_strdel(&name1);
		app_error(self);
	}
	ft_strdel(&name2);
	ft_strdel(&name1);
	return (1);
}
