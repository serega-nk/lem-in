/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/23 21:46:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	load_link_parse(t_app *self, char **aname1, char **aname2)
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
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	load_link_attach(t_app *self, char *name1, char *name2)
{
	t_room	*room1;
	t_room	*room2;
	char	*pair1;
	char	*pair2;
	t_bool	ret;

	ret = FALSE;
	pair1 = ft_xstrdup3(name1, " ", name2);
	pair2 = ft_xstrdup3(name2, " ", name1);
	if (hashtab_insert(self->pairs, pair1, NULL) &&
		hashtab_insert(self->pairs, pair2, NULL) &&
		hashtab_get(self->rooms, name1, (void **)&room1) &&
		hashtab_get(self->rooms, name2, (void **)&room2))
	{
		list_push_back(self->links, link_create(&room1->out, &room2->in, 1));
		list_push_back(self->links, link_create(&room2->out, &room1->in, 1));
		ret = TRUE;
	}
	ft_strdel(&pair2);
	ft_strdel(&pair1);
	return (ret);
}

t_bool			load_link(t_app *self)
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
	return (TRUE);
}
