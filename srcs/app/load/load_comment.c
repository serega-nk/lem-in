/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 17:57:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	load_comment(t_app *self)
{
	if (!parse_skip(&self->line, "#"))
		return (FALSE);
	if (!parse_goto(&self->line, "\n"))
		app_error(self);
	if (!parse_none(&self->line))
		app_error(self);
	return (TRUE);
}
