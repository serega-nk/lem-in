/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/10 20:27:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "deque.h"
# include "gnl.h"
# include "parse.h"
# include "hashtab.h"
# include "list.h"

typedef struct s_room	t_room;
typedef struct s_ant	t_ant;
typedef struct s_app	t_app;

struct	s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	t_hashtab	*links;
	int			level;
	int			lock;
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
	t_gnl		*gnl;
	t_list		*lines;
	char		*line;
	char		*key;
	int			state;
	int			signal_start;
	int			signal_end;
	t_room		*room_start;
	t_room		*room_end;
	int			number;
	t_hashtab	*rooms;
	t_hashtab	*coords;
	t_list		*routes;
	t_list		*ants;
	int			id_ant;
	int			capacity;
	int			count;
	t_list_iter		*iter;
};

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
void	load_check(t_app *self);

t_room	*room_create(void);
void	room_destroy(t_room **aself);
int		room_lock(t_room *self);
void	room_unlock(t_room *self);

t_ant	*ant_create(int id, t_list *route);
void	ant_destroy(t_ant **aself);
int		ant_move(t_ant *self);
void	ant_print(t_ant *self);
int		ant_finish(t_ant *self);

#endif
