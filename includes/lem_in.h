/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/28 04:39:20 by bconchit         ###   ########.fr       */
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

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_app	t_app;

struct	s_room
{
	char	*name;
	char	*key_coord;
	int		coord_x;
	int		coord_y;
};

struct	s_link
{
	char	*name1;
	char	*name2;
};

struct	s_app
{
	t_gnl		*gnl;
	t_queue		*lines;
	char		*line;
	int			state;
	int			signal_start;
	int			signal_end;
	t_room		*room_start;
	t_room		*room_end;
	int			number;
	t_queue		*rooms;
	t_queue		*links;
};

void	app_error(t_app *self);
void	app_load(t_app *self);
void	app_calc(t_app *self);
void	app_play(t_app *self);
void	app_free(t_app *self);

int		load_comment(t_app *self);
int		load_number(t_app *self);
int		load_room(t_app *self);
int		load_link(t_app *self);

void	load_while(t_app *self);
void	load_check(t_app *self);

t_room	*room_create(void);
void	room_destroy(t_room **aself);

t_link	*link_create(void);
void	link_destroy(t_link **aself);

#endif
