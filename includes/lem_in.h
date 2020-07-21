/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 15:12:19 by bconchit         ###   ########.fr       */
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

typedef enum e_type		t_type;

typedef struct s_link	t_link;
typedef struct s_save	t_save;
typedef struct s_room	t_room;
typedef struct s_option	t_option;
typedef struct s_ant	t_ant;
typedef struct s_app	t_app;

enum	e_type
{
	LINK_EDGE,
	LINK_REVERSE,
	LINK_NONE
};

struct	s_link
{
	t_type			type;
	t_room			*room1;
	t_room			*room2;
};

struct	s_save
{
	t_link			*link;
	int				level;
};

struct	s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				lock;
	t_room			*path;
	t_save			in;
	t_save			out;	
};

struct	s_option
{
	int				steps;
	t_heap			*routes;
};

struct	s_ant
{
	int				id;
	t_list_iter		*iter;
	t_room			*room;
	t_room			*next;
};

struct	s_app
{
	char			*line;
	int				state;
	int				signal_start;
	int				signal_end;
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
int			room_lock(t_room *self);
void		room_unlock(t_room *self);

t_option	*option_create(int steps, t_heap *routes);
void		option_destroy(t_option **aself);

t_ant		*ant_create(int id, t_list *route);
void		ant_destroy(t_ant **aself);
int			ant_move(t_ant *self);
void		ant_print(t_ant *self);
int			ant_finish(t_ant *self);

void		app_error(t_app *self);
void		app_load(t_app *self);
void		app_calc(t_app *self);
void		app_output(t_app *self);
void		app_free(t_app *self);

int			load_signal(t_app *self);
int			load_comment(t_app *self);
int			load_number(t_app *self);
int			load_room(t_app *self);
int			load_link(t_app *self);
void		load_while(t_app *self);
void		load_check(t_app *self);

t_bool		calc_shortest_path(t_app *self);

// void		calc_prepare(t_app *self);
// int			calc_bellman_ford(t_app *self);
// void		calc_suurballe(t_app *self);
// int			calc_excess(t_app *self);
// void		calc_populate(t_app *self);

#endif
