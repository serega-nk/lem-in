/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:04:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:42:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_list		t_list;
typedef struct s_list_item	t_list_item;
typedef struct s_list_iter	t_list_iter;

struct			s_list
{
	t_list_item		*head;
	t_list_item		*tail;
	size_t			count;
};

struct			s_list_item
{
	t_list_item		*next;
	void			*data;
};

struct			s_list_iter
{
	t_list			*list;
	t_list_item		**awalk;
	t_bool			remove;
};

t_list			*list_create(void);
void			list_destroy(t_list **aself);

void			list_clean(t_list *self, void (*delf)());

t_bool			list_pop_front(t_list *self, void **adata);
void			list_push_back(t_list *self, void *data);
void			list_push_front(t_list *self, void *data);

t_list_item		*list_item_create(void);
void			list_item_destroy(t_list_item **aself);

t_list_iter		*list_iter_create(t_list *list);
void			list_iter_destroy(t_list_iter **aself);

t_bool			list_iter_next(t_list_iter *self, void **adata);
t_bool			list_iter_remove(t_list_iter *self, void (*delf)());
void			*list_iter_next2(t_list_iter *self);

#endif
