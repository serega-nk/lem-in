/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 15:02:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "deque.h"
# include "gnl.h"
# include "queue.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_app	t_app;

struct	s_room
{
	char	*name;
	int		coord_x;
	int		coord_y;
};

struct	s_link
{
	t_room	*room1;
	t_room	*room2;
};

struct	s_app
{
	t_gnl		*gnl;
	t_queue		*lines;
	char		*line;
	int			state;
	// int			flag_start;
	// int			flag_end;
	// void		*room_start;
	// void		*room_end;
	int			number_of_ants;
	// void		*rooms;
	// void		*links;
};

void	app_error(t_app *self);
void	app_load(t_app *self);
void	app_calc(t_app *self);
void	app_play(t_app *self);
void	app_free(t_app *self);

void	load_while(t_app *self);
void	load_check(t_app *self);


#endif
