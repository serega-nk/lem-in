/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:49:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	load_link_parse(char *line)
{
	char	*name1;
	char	*name2;

	name1 = NULL;
	name2 = NULL;
	if (parse_str(&line, &name1, "- \n") &&
		name1[0] != 'L' &&
		parse_skip(&line, "-") &&
		parse_str(&line, &name2, "- \n") &&
		name2[0] != 'L' &&
		parse_skip(&line, "\n") &&
		parse_none(&line))
	{
		ft_strdel(&name1);
		ft_strdel(&name2);
		return (1);
	}
	ft_strdel(&name1);
	ft_strdel(&name2);
	return (0);
}

int			load_link(t_app *self)
{
	if (self->signal_start || self->signal_end)
		app_error(self);
	if (!load_link_parse(self->line))
		app_error(self);
	return (1);
}
