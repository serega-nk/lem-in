/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/28 05:32:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_comment(t_app *self)
{
	if (!parse_skip(&self->line, "#"))
		return (0);
	if (!parse_goto(&self->line, "\n"))
		app_error(self);
	if (!parse_none(&self->line))
		app_error(self);
	return (1);
}
