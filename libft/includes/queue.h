/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:05:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/03 19:22:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_queue_item	t_queue_item;
typedef struct s_queue		t_queue;

struct			s_queue_item
{
	t_queue_item	*next;
	void			*data;
};

struct			s_queue
{
	t_queue_item	*head;
	t_queue_item	*tail;
	t_queue_item	**awalk;
	int				walk_remove;
	size_t			size;
};

t_queue_item	*queue_item_create(void);
void			queue_item_destroy(t_queue_item **aself);

t_queue			*queue_create(void);
void			queue_destroy(t_queue **aself);
void			queue_clean(t_queue *self, void (*delf)());
int				queue_pop_front(t_queue *self, void **adata);
void			queue_push_front(t_queue *self, void *data);
void			queue_push_back(t_queue *self, void *data);

int				queue_start(t_queue *self);
int				queue_next(t_queue *self, void **adata);
int				queue_remove(t_queue *self, void (*delf)());

#endif
