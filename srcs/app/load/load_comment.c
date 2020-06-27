/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:19:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:20:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		load_comment(t_app *self)
{
	// if (!check_ln(self->line))
	// 	app_error(self);
	// skip comment
	if (*self->line == '#')
		return (1);
	// if (self->signal_start || self->signal_end)
	// 	app_error(self);
	// if (self)
	// 	return (0);
	return (0);
}
