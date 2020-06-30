/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/30 05:15:14 by bconchit         ###   ########.fr       */
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
# include "queue.h"
# include "hashtab.h"
# include "heap.h"

typedef struct s_room	t_room;
typedef struct s_app	t_app;

struct	s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	t_hashtab	*links;
	int			level;
	t_room		*walk;
	int			lock;
};

struct	s_app
{
	t_gnl		*gnl;
	t_queue		*lines;
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
};

void	app_error(t_app *self);
void	app_load(t_app *self);
void	app_calc(t_app *self);
void	app_play(t_app *self);
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

#endif
