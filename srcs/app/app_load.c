/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:47:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 00:17:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static int	app_load_numbers_of_ants(t_app *self)
// {
// 	size_t	len;

// 	while (gnl_readline(self->gnl, &self->line) > 0)
// 	{
// 		if (!app_load_line(self))
// 		{
// 			ft_strdel(&self->line);
// 			return (0);
// 		}
// 		ret = (len = ft_strlen(self->line)) > 0;
// 		if (ret)
// 		{
// 			self->line[len - 1] != '\n';
// 		}
// 		if ((ret = check(self->line))
// 		{
// 			if (ft_strequ(self->line, "##start") ||
// 				ft_strequ(self->line, "##end"))
// 				ret = 0;
// 		}





// 		len = ft_strlen(self->line);
// 		if (len == 0)
// 			app_error(self);
// 		if (self->line[len - 1] != '\n')
// 			app_error(self);
		
// 		{
// 			ft_strdel(&self->line);
// 			return (0);
// 		}
// 		if (self->line[0] == '#')
// 		{
// 			if (ft_strequ(line, "##start") ||
// 				ft_strequ(line, "##end"))
// 			{
// 				ft_strdel(&self->line);
// 				return (0);
// 			}
// 		}
// 		else
// 		{
// 			// read number
// 		}
// 		ft_strdel(&self->line);
// 	}
// 	return (0);
// }


	
static void		app_load_while(t_app *self)
{
	size_t	len;

	len = ft_strlen(self->line);
	if (len == 0)
		app_error(self);
	if (self->line[len-1] != '\n')
		app_error(self);
	self->line[--len] = '\0';
	if (self->line[0] == '#')
		return ;
	ft_printf("|%s|\n", self->line);
	
	// The rooms, which are defined by: name coord_x coord_y
	// The links, which are defined by: name1-name2
	// All of it is broken by comments, which start with #

	// All of it is broken by comments, which start with #

	// Numbers of ants

	// The rooms’ names won’t necessarily be numbers, and they won’t
	// necessarily be in the right and continuous order (we will find rooms
	// with names such as zdfg, qwerty, etc...) But most importantly, a
	// room will never start with the character L nor the character #

	// The rooms, which are defined by: name coord_x coord_y
	// The rooms’ coordinates will always be integers.

	// The links, which are defined by: name1-name2
}

void			app_load(t_app *self)
{
	self->gnl = gnl_create(STDIN_FILENO);
	while (gnl_readline(self->gnl, &self->line) > 0)
	{
		app_load_while(self);
		ft_strdel(&self->line);
	}
	gnl_destroy(&self->gnl);
}
