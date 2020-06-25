/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:05:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 21:47:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_queue_item	t_queue_item;
typedef struct s_queue		t_queue;

struct	s_queue_item
{
	t_queue_item	*head;
	t_queue_item	*tail;
};

struct	s_queue
{
	size_t	size;
	void	*head;
	void	*tail;
};

t_queue	*queue_create(void);
void	queue_destroy(t_queue **aself);
void	queue_clean(t_queue *self);
void	*queue_pop_front(t_queue *self);
void	queue_push_back(t_queue *self, void *data);

#endif
