/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 04:14:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 13:17:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	load_while(t_app *self)
{
	if (self)
		self = NULL;
}


		// if (self->state == 0)
		// 	app_load_number_of_ants(self, self->line);
		// else if (self->state == 1)
		// 	app_load_the_rooms(self, self->line);
		// else
		// 	app_load_the_links(self, self->line);




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

// static int		parse_number(char **addr, int *avalue)
// {
// 	long	prev;
// 	long	curr;

// 	if (ft_isdigit(**addr))
// 	{
// 		if (**addr == '0' && ft_isdigit(*(*addr + 1)))
// 			return (0);
// 		curr = 0;
// 		while (ft_isdigit(**addr))
// 		{
// 			prev = curr;
// 			curr = curr * 10 + (*(*addr)++ - '0');
// 			if ((int)curr < (int)prev)
// 				return (0);
// 		}
// 		*avalue = (int)curr;
// 		return (1);
// 	}
// 	return (0);
// }

// static int		parse_name(char **addr, char **avalue)
// {
// 	char	*ptr;

// 	ptr = *addr;
// 	if (*ptr == 'L')
// 		return (0);
// 	while (*ptr)
// 	{
// 		if (*ptr == ' ' || *ptr == '-')
// 			break ;
// 		ptr++;
// 	}
// 	if (ptr > *addr)
// 	{
// 		*avalue = (char *)ft_xcheck((void *)ft_strndup(*addr, ptr - *addr));
// 		*addr = ptr;
// 		return (1);
// 	}
// 	return (0);
// }

	
// static int		parse_number_of_ants(char *line, int *avalue)
// {
// 	return (parse_int(&line, avalue) && *line == '\0');
// }

// static int		parse_the_rooms(char *line, t_room *room)
// {
// 	return (parse_int(&line, avalue) && *line == '\0');
// }

// static int		parse_the_links(char *line, t_room *room)
// {
// 	return (parse_int(&line, avalue) && *line == '\0');
// }
	
// static void		app_load_while(t_app *self, char *line)
// {
// 	if (self->state == 0)
// 	{
// 		if (!parse_number_of_ants(self->line, self->number_of_ants))
// 			app_error();
// 		self->state++;
// 		return ;
// 	}
// 	if (self->state == 1)
// 	{
// 		room = room_create();
// 		if (parse_the_rooms(self->line, room)
// 		{
// 			return ;
// 		}
// 		room_destroy(&room);
// 		self->state++;
// 	}
// 	room = room_create();
// 	if (parse_the_links(self->line, room))
// 	{

// 		return ;
// 	}
// 	room_destroy(&room);
// 	app_error();

	// len = ft_strlen(self->line);
	// if (len == 0)
	// 	app_error(self);
	// if (self->line[len-1] != '\n')
	// 	app_error(self);
	// self->line[--len] = '\0';
	// if (ft_strequ(self->line, "##start"))
	// {
	// 	if (self->flag_start || self->flag_end)
	// 		app_error(self);
	// 	self->flag_start = 1;
	// 	return ;
	// }
	// if (ft_strequ(self->line, "##end"))
	// {
	// 	if (self->flag_start || self->flag_end)
	// 		app_error(self);
	// 	self->flag_end = 1;
	// 	return ;
	// }
	// if (self->line[0] == '#')
	// 	return ;
	// if (self->state != 1 && (self->flag_start || self->flag_end))
	// 	app_error(self);

	// char *str = "-214748369 sss";
	// char *ptr = str;
	// int value;

	// if (parse_int(&ptr, &value))
	// {
	// 	ft_printf("|%s| |%d|\n", ptr, value);
	// }
	// else
	// {
	// 	ft_printf("###\n");
	// }
	// app_error(self);

	// if (self->state == 0)
	// {
	// 	if (ft_sscanf(self->line, "%d\n", &self->number_of_ants) != 1)
	// 		app_error(self);
	// 	self->state++;
	// 	return ;
	// }


	// if (self->state == 0)
	// {
	// 	// parse numbers of ants
	// 	char	*ptr;

	// 	ptr = self->line;
	// 	if (!parse_number(&ptr, &self->number_of_ants) || *ptr != '\0')
	// 		app_error(self);
	// 	self->state++;
	// 	ft_printf("PARSE numbers of ants = %d\n", self->number_of_ants);
	// 	return ;
	// }
	// if (self->state == 1)
	// {
	// 	ft_printf("LINE = |%s|\n", self->line);
	// 	char *name;
	// 	char *ptr = self->line;
	// 	if (!parse_name(&ptr, &name))
	// 		app_error(self);
	// 	if (*ptr == '-')
	// 	{
	// 		self->state++;
	// 	}
	// 	else
	// 	{
	// 		if (*ptr != ' ')
	// 			app_error(self);
	// 		ptr++;

	// 		t_room	temp;
	// 		t_room *room;
	// 		room = &temp;

	// 		if (3 == ft_sscanf(self->line, "%s %d %d\n", 
	// 			&room->name, &room->coord_x, &room->coord_y))
	// 		{
	// 			// 
	// 			return ;
	// 		}


	// 		// int value = room->coord_x;

	// 		// if (ft_scanf(line, "%s %d %d\n", &room->name, &room->coord_x, &room->coord_y)) == 3)
	// 		// {
				
	// 		// }


	// 		// if (parse_name(&ptr, &room->name) &&
	// 		// 	parse_skip(&ptr, " ") &&
	// 		// 	parse_number(&ptr, &room->coord_x) &&
	// 		// 	parse_skip(&ptr, " ") &&
	// 		// 	parse_number(&ptr, &room->coord_y) && 
	// 		// 	parse_end(&ptr)
	// 		// {

	// 		// }
	// 		// else
	// 		// {

	// 		// }

	// 		if (parse_number(&ptr, &room->coord_x) && *ptr == ' ' && ptr++ &&
	// 			parse_number(&ptr, &room->coord_y) && *ptr == '\0')
	// 		{
	// 			ft_printf("COORD X = |%d|, ", room->coord_x);
	// 			ft_printf("COORD Y = |%d|\n", room->coord_y);
	// 		}
	// 		else
	// 		{
	// 			app_error(self);
	// 		}

	// 		//if (!parse_number(&ptr, &value) || *ptr != ' ')

	// 		// if (!parse_number(&ptr, &value) || *ptr != ' ')
	// 		// 	app_error(self);
	// 		// ft_printf("COORD X = |%d|\n", value);
	// 		// ptr++;
	// 		// if (!parse_number(&ptr, &value))
	// 		// 	app_error(self);
	// 		// if (*ptr != '\0')
	// 		// 	app_error(self);
	// 		// ft_printf("COORD Y = |%d|\n", value);

	// 		// parse room
	// 		if (self->flag_start)
	// 		{
	// 			self->flag_start = 0;
	// 			self->room_start = NULL;
	// 		}
	// 		if (self->flag_end)
	// 		{
	// 			self->flag_end = 0;
	// 			self->room_end = NULL;
	// 		}
	// 		return ;		
	// 	}
	// }

	// ft_printf("|%s|\n", self->line);
	
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
//}

// static void		app_load_number_of_ants(t_app *self, char *line)
// {
// 	if (parse_int(&line, &self->number_of_ants) && *line == '\0')
// 	{
// 		if (self->number_of_ants <= 0)
// 			app_error(self);
// 		self->state++;
// 		return ;
// 	}
// 	app_error();
// }

// static void		app_load_the_rooms(t_app *self, char *line)
// {
// 	room = room_create();
// 	if (parse_name(&line, &room->name) && *line == ' ' && line++ &&
// 		parse_int(&line, &room->coord_x) && *line == ' ' && line++ &&
// 		parse_int(&line, &room->coord_y) && *line == '\0')
// 	{

// 		return ;
// 	}
// 	room_destroy(&room);
// 	self->state++;
// 	app_load_the_links(self, self->line);
// }

// static void		app_load_the_links(t_app *self, char *line)
// {
// 	char	*name1;
// 	char	*name2;

// 	name1 = NULL;
// 	name2 = NULL;
// 	if (parse_name(&line, &name1) && *line == ' ' && line++ &&
// 		parse_name(&line, &name2) && *line == '\0')
// 	{
		
// 		ft_strdel(&name2);
// 		ft_strdel(&name1);
// 		return ;
// 	}
// 	ft_strdel(&name2);
// 	ft_strdel(&name1);
// 	app_error();
// }
