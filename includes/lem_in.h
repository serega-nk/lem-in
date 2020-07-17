/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 20:15:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "gnl.h"
# include "parse.h"
# include "hashtab.h"
# include "list.h"

typedef enum e_type		t_type;
typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_ant	t_ant;
typedef struct s_app	t_app;

enum	e_type
{
	TYPE_ROOM,
	TYPE_IN,
	TYPE_OUT,
	TYPE_START,
	TYPE_END
};

struct	s_room
{
	char			*name;
	t_type			type;
	int				coord_x;
	int				coord_y;
	t_hashtab		*links;
	int				level;
	t_room			*path;
	t_room			*route;
	int				lock;
};

struct	s_link
{
	t_room			*room1;
	t_room			*room2;
	int				weight;
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
	t_gnl			*gnl;
	t_list			*lines;
	char			*line;
	char			*key;
	int				state;
	int				signal_start;
	int				signal_end;
	t_room			*room_start;
	t_room			*room_end;
	int				number;
	t_hashtab		*rooms;
	t_hashtab		*coords;
	t_list			*links;
	t_list			*routes;
	t_list			*ants;
};

t_room	*room_create(void);
void	room_destroy(t_room **aself);
int		room_lock(t_room *self);
void	room_unlock(t_room *self);

t_link	*link_create(t_room *room1, t_room *room2, int weight);
void	link_destroy(t_link **aself);

t_ant	*ant_create(int id, t_list *route);
void	ant_destroy(t_ant **aself);
int		ant_move(t_ant *self);
void	ant_print(t_ant *self);
int		ant_finish(t_ant *self);

void	app_error(t_app *self);
void	app_load(t_app *self);
void	app_calc(t_app *self);
void	app_output(t_app *self);
void	app_free(t_app *self);

int		load_signal(t_app *self);
int		load_comment(t_app *self);
int		load_number(t_app *self);
int		load_room(t_app *self);
int		load_link(t_app *self);
void	load_while(t_app *self);
void	load_final(t_app *self);

void	calc_preparation(t_app *self);
void	calc_bellman_ford(t_app *self);
void	calc_suurballe(t_app *self);
int		calc_excess(t_app *self);
void	calc_populate(t_app *self);

#endif
