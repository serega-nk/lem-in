/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_disjoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:12:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/22 05:48:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static t_link	*calc_disjoint_link(t_room *room)
// {
// 	if (room->path &&
// 		room->in.link && room->out.link &&
// 		room->in.level <= room->out.level)
// 	{
// 		return (room->out.link);
// 	}
// 	else
// 	{
// 		return (room->in.link);
// 	}
// }



// static t_link	*calc_disjoint_link(t_room *room, t_type state)
// {
// 	if (room->path && state == LINK_EDGE)
// 	{
// 		ft_printf("# TEST   %s\n", room->name);
// 		//ft_printf("# LINK %d %s %s\n", link->type, link->room1->name, link->room2->name);
// 		ft_printf("# OUT LINK %d %s %s\n", room->out.link->type, room->out.link->room1->name, room->out.link->room2->name);
// 		return (room->out.link);
// 	}
// 	return (room->in.link);
// }

// static void		calc_disjoint_next(t_room *room, t_link **aprev, t_link **acurr, t_link **anext)
// {
// 	// *aprev = *acurr;
// 	// *acurr = *anext;
// 	// if (room == (*anext)->room1)
// 	// {
// 	// 	(*anext)->room1 = (*anext)->room2;
// 	// 	(*anext)->room2 = room;
// 	// }
// 	// *anext = (*anext)->room1->in.link;

// 	// if (link->type == LINK_EDGE)
// 	// {
// 	// 	if (link->room1->path)
// 	// 	{
// 	// 		return (link->room1->out.link);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		return (link->room1->in.link);
// 	// 	}			
// 	// }
// 	// else if (link->type == LINK_REVERSE)
// 	// {
// 	// 	return (link->room1->in.link);
// 	// }
// 	// else
// 	// {
// 	// 	app_error(self);
// 	// }
// 	// return (link->room1->in.link);
// }

void			calc_disjoint(t_app *self)
{
	t_room		*room;
	t_link		*prev;
	t_link		*link;
	t_link		*next;
	
	t_list		*list_reverse;
	t_list		*list_reverse_rev;
	t_list		*list_edge;
	t_list		*list_none;

	list_reverse = list_create();
	list_reverse_rev = list_create();
	list_edge = list_create();
	list_none = list_create();

	room = self->room_end;
	prev = NULL;
	link = NULL;
	next = room->in.link;
	//ft_printf("# ROOM %s\n", room->name);

	t_hashtab *test;
	char	key[1000];

	test = hashtab_create();

	while (room != self->room_start)
	{
		prev = link;
		link = next;

		if (room == link->room1)
			next = link->room2->in.link;
		else
			next = link->room1->in.link;

		// calc_disjoint_next(room, &prev, &link, &next);

		if (link->type == LINK_EDGE)
		{
			//ft_printf("# LINK_EDGE  %s, %s\n", link->room1->name, link->room2->name);
			//link->type = LINK_REVERSE;

			if (room == link->room1)
			{
				room->path = link->room2;
				ft_sprintf(key, "%p", link);
				if (!hashtab_insert(test, key, NULL))
				{
					ft_printf("###### AAAAA\n");
					app_error(self);
				}
				list_push_back(list_reverse_rev, link);
			}
			else
			{
				room->path = link->room1;
				ft_sprintf(key, "%p", link);
				if (!hashtab_insert(test, key, NULL))
				{
					
					list_push_back(list_none, link);
					ft_printf("###### AAAAA\n");
					//app_error(self);
				}
				else
					list_push_back(list_reverse, link);
			}
		}
		else if (link->type == LINK_REVERSE)
		{
			/// make; cat 0.txt | ./lem-in | grep "#"
			if (prev->type == LINK_EDGE)
			{
				ft_printf("# CCC ");
				ft_printf("# LINK_REVERSE  %s, %s    %s\n", link->room1->name, link->room2->name, room->name);
				//link->type = LINK_NONE;
				list_push_back(list_none, link);
			}
			else if (next->type == LINK_EDGE)
			{
				ft_printf("# BBB ");
				ft_printf("# LINK_REVERSE  %s, %s    %s\n", link->room1->name, link->room2->name, room->name);
				//link->type = LINK_NONE;
				room->path = NULL;
				list_push_back(list_none, link);
			}
			else
			{
				ft_printf("# AAA ");
				ft_printf("# LINK_REVERSE  %s, %s    %s\n", link->room1->name, link->room2->name, room->name);
				//link->type = LINK_EDGE;
				room->path = NULL;
				list_push_back(list_none, link);
			}
			
			// ft_printf("#PATH   %s\n",  room->name);
			// if (prev->type != LINK_REVERSE && next->type != LINK_EDGE)
			// {
			// 	ft_printf("# AAA ");
			// 	ft_printf("# LINK_REVERSE  %s, %s    %s\n", link->room1->name, link->room2->name, room->name);
			// 	link->type = LINK_EDGE;
			// 	//room->path =
			// }
			// else
			// {
			// 	link->type = LINK_NONE;	
			// }
			
			
	
					
		}
		else
		{
			ft_printf("ELSE\n");
			app_error(self);
		}
		

		// if (room == walk->room1)
		// {
		// 	walk->room1 = walk->room2;
		// 	walk->room2 = room;
		// }		
		// if (walk->type == LINK_EDGE)
		// {
		// 	walk = walk->
		// }

		// if (room == link->room1)
		// {
		// 	link->room1 = link->room2;
		// 	link->room2 = room;
		// }

		
		// if (link->type == LINK_REVERSE)
		// {
		// 	room = link->room1;

		// }

		if (room == link->room1)
			room = link->room2;
		else
			room = link->room1;

		ft_printf("# ROOM %s\n", room->name);
	}

	//app_error(self);




	// t_list		*list;

	// list = list_create();
	// room = self->room_end;
	// link = NULL;
	// while (room != self->room_start)
	// {
	// 	ft_printf("# ROOM %s\n", room->name);
	// 	if (room->path && link && link->type == LINK_EDGE)
	// 		link = room->out.link;
	// 	else
	// 		link = room->in.link;

	// 	if (room == link->room1)
	// 	{
	// 		link->room1 = link->room2;
	// 		link->room2 = room;			
	// 	}
	// 	list_push_back(list, link);
	// 	room = link->room1;		
	// }

	// t_list_iter *iter;

	// iter = list_iter_create(list);
	// t_link	*prev = NULL;
	// while (list_iter_next(iter, (void **)&link))
	// {
	// 	if (link->type == LINK_EDGE)
	// 	{
	// 		if (prev && prev->type == LINK_NONE)
	// 		{
	// 			ft_printf("# PREV %d\n", prev->type);
	// 		}			
	// 		ft_printf("# LINK_EDGE  %s, %s\n", link->room1->name, link->room2->name);
	// 		link->type = LINK_REVERSE;
	// 	}
	// 	else if (link->type == LINK_REVERSE)
	// 	{
	// 		if (prev)
	// 		{
	// 			ft_printf("# PREV %d\n", prev->type);
	// 		}
	// 		ft_printf("# LINK_REVERSE  %s, %s\n", link->room1->name, link->room2->name);
	// 		link->type = LINK_NONE;
	// 		if (prev)
	// 			prev = link;
	// 	}
	// 	prev = link;
	// }
	// list_iter_destroy(&iter);
	// list_destroy(&list);

	// t_type		state;
	//t_list		*list_rev;
	//t_list		*list_non;

	//list_rev = list_create();
	//list_non = list_create();

	// room = self->room_end;
	// state = LINK_NONE;
	// ft_printf("# ROOM %s\n", room->name);
	// while (room != self->room_start)
	// {
	// 	link = calc_disjoint_link(room, state);
	// 	//ft_printf("# ");
	// 	if (link->type == LINK_EDGE)
	// 	{
	// 		if (link->room1 == room)
	// 		{
	// 			//ft_printf("SWAP ");
	// 			link->room1 = link->room2;
	// 			link->room2 = room;
	// 		}
	// 		link->type = LINK_REVERSE;
	// 		//ft_printf("LINK_REVERSE ");
	// 		room->path = link->room1;
	// 		state = LINK_EDGE;
	// 		room = link->room1;
	// 	}
	// 	else if (link->type == LINK_REVERSE)
	// 	{
	// 		if (link->room2->path && link->room2->out.link->type == LINK_REVERSE)

	// 		// if (state == LINK_REVERSE)
	// 		{
	// 			ft_printf("# TTT LINK %d %s %s     | %s \n", link->type, link->room1->name, link->room2->name, room->name);
	// 			link->type = LINK_EDGE;
	// 			room->path = NULL;
	// 		}
	// 		else
	// 		{
	// 			ft_printf("# AAA LINK %d %s %s     | %s \n", link->type, link->room1->name, link->room2->name, room->name);
				
	// 		}

	// 		state = LINK_REVERSE;
	// 		room = link->room2;
	// 		//app_error(self);
	// 		// link->type = LINK_NONE;
	// 		// //list_push_back(list_non, link);
	// 		// // link->room1->path->path2 = 
	// 		// room->path = link->room1->path;
	// 		// room->path->path2 = room;
	// 		// link->room1->path = NULL;
	// 		// room = link->room1;
	// 	}
	// 	else
	// 		app_error(self);
	// 	//ft_printf("%d %s %s\n", link->type, link->room1->name, link->room2->name);
		
	// 	ft_printf("# ROOM %s\n", room->name);
	// }	
	
	t_list_iter *iter;

	iter = list_iter_create(list_reverse);
	while (list_iter_next(iter, (void *)&link))
	{
		link->type = LINK_REVERSE;
	}
	list_iter_destroy(&iter);
	
	iter = list_iter_create(list_reverse_rev);
	while (list_iter_next(iter, (void *)&link))
	{
		t_room *room = link->room1; 
		link->room1 = link->room2;
		link->room2 = room;
		link->type = LINK_REVERSE;
	}
	list_iter_destroy(&iter);

	iter = list_iter_create(list_edge);
	while (list_iter_next(iter, (void *)&link))
	{
		link->type = LINK_EDGE;
	}
	list_iter_destroy(&iter);
	
	iter = list_iter_create(list_none);
	while (list_iter_next(iter, (void *)&link))
	{
		link->type = LINK_NONE;
	}
	list_iter_destroy(&iter);

	list_destroy(&list_edge);
	list_destroy(&list_none);
	list_destroy(&list_reverse_rev);
	list_destroy(&list_reverse);
}
