/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 18:54:51 by bconchit         ###   ########.fr       */
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
		*(*aname2) != 'L' &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
	{
		return (1);
	}
	return (0);
}

static int	load_link_attach(t_app *self, char *name1, char *name2)
{
	t_room	*room1;
	t_room	*room2;
	t_link	*link1;
	t_link	*link2;

	if (hashtab_get(self->rooms, name1, (void **)&room1) &&
		hashtab_get(self->rooms, name2, (void **)&room2))
	{
		link1 = link_create(room1, room2, 1);
		link2 = link_create(room2, room1, 1);
		if (hashtab_insert(room1->links, name2, link1) &&
			hashtab_insert(room2->links, name1, link2))
		{
			list_push_back(self->links, link1);
			list_push_back(self->links, link2);
			return (1);
		}
		link_destroy(&link2);
		link_destroy(&link1);
	}
	return (0);
}

int			load_link(t_app *self)
{
	char	*name1;
	char	*name2;

	if (self->signal_start || self->signal_end)
		app_error(self);
	name1 = NULL;
	name2 = NULL;
	if (!load_link_parse(self, &name1, &name2) ||
		!load_link_attach(self, name1, name2))
	{
		ft_strdel(&name2);
		ft_strdel(&name1);
		app_error(self);
	}
	ft_strdel(&name2);
	ft_strdel(&name1);
	return (1);
}
