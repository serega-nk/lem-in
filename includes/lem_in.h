/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:58:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 00:10:57 by bconchit         ###   ########.fr       */
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
typedef struct s_app	t_app;

struct	s_room
{
	char	*name;
	int		coord_x;
	int		coord_y;
};

struct	s_app
{
	t_gnl	*gnl;
	char	*line;
	int		mode;
	size_t	number_of_ants;
	void	*rooms;
	void	*links;
};

void	app_error(t_app *self);
void	app_load(t_app *self);
void	app_calc(t_app *self);
void	app_play(t_app *self);
void	app_free(t_app *self);

#endif
