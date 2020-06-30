/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 07:44:07 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 21:05:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_deque_item		t_deque_item;
typedef struct s_deque			t_deque;

struct			s_deque_item
{
	t_deque_item	*prev;
	t_deque_item	*next;
	void			*data;
};

struct			s_deque
{
	t_deque_item	*head;
	t_deque_item	*tail;
	size_t			size;
};

t_deque_item	*deque_item_create(void);
void			deque_item_destroy(t_deque_item **aself);

t_deque			*deque_create(void);
void			deque_destroy(t_deque **aself);
void			deque_clean(t_deque *self);
void			*deque_pop_front(t_deque *self);
void			*deque_pop_back(t_deque *self);
void			deque_push_front(t_deque *self, void *data);
void			deque_push_back(t_deque *self, void *data);

#endif
