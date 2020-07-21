/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 19:27:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "ft_printf.h"
# include "gnl.h"
# include "hashtab.h"
# include "heap.h"
# include "libft.h"
# include "list.h"
# include "parse.h"

typedef enum e_state	t_state;
typedef enum e_type		t_type;

typedef struct s_link	t_link;
typedef struct s_save	t_save;
typedef struct s_room	t_room;
typedef struct s_option	t_option;
typedef struct s_ant	t_ant;
typedef struct s_app	t_app;

enum		e_state
{
	LOAD_NUMBER,
	LOAD_ROOM,
	LOAD_LINK
};

enum		e_type
{
	LINK_EDGE,
	LINK_REVERSE,
	LINK_NONE
};

struct		s_link
{
	t_type			type;
	t_room			*room1;
	t_room			*room2;
};

struct		s_save
{
	t_link			*link;
	int				level;
};

struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				lock;
	t_room			*path;
	t_save			in;
	t_save			out;
};

struct		s_option
{
	size_t			steps;
	t_heap			*routes;
};

struct		s_ant
{
	int				id;
	t_list_iter		*iter;
	t_room			*room;
	t_room			*next;
};

struct		s_app
{
	char			*line;
	t_state			state;
	t_bool			signal_start;
	t_bool			signal_end;
	t_room			*room_start;
	t_room			*room_end;
	int				number;
	t_gnl			*gnl;
	t_list			*lines;
	char			coord[100];
	t_hashtab		*coords;
	t_hashtab		*rooms;
	t_hashtab		*pairs;
	t_list			*links;
	t_list			*paths;
	t_heap			*options;
	t_list			*ants;
};

t_link		*link_create(t_room *room1, t_room *room2);
void		link_destroy(t_link **aself);

t_room		*room_create(void);
void		room_destroy(t_room **aself);
void		room_reset(t_room *self);
t_bool		room_lock(t_room *self);
void		room_unlock(t_room *self);

t_option	*option_create(void);
void		option_destroy(t_option **aself);

t_ant		*ant_create(int id, t_list *route);
void		ant_destroy(t_ant **aself);
t_bool		ant_move(t_ant *self);
void		ant_print(t_ant *self);
t_bool		ant_finish(t_ant *self);

void		app_error(t_app *self);
void		app_load(t_app *self);
void		app_calc(t_app *self);
void		app_output(t_app *self);
void		app_free(t_app *self);

t_bool		load_signal(t_app *self);
t_bool		load_comment(t_app *self);
t_bool		load_number(t_app *self);
t_bool		load_room(t_app *self);
t_bool		load_link(t_app *self);
void		load_while(t_app *self);
void		load_check(t_app *self);

t_bool		calc_shortest(t_app *self);
void		calc_disjoint(t_app *self);
t_option	*calc_option(t_app *self);
void		calc_populate(t_app *self, t_heap *routes);

#endif
