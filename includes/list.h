/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:04:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 15:03:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"
# include "ft_xexit.h"

# define LIST_FOREACH_REMOVE -1
# define LIST_FOREACH_STOP 0
# define LIST_FOREACH_NEXT 1

typedef struct s_list_item	t_list_item;
typedef struct s_list		t_list;

struct			s_list_item
{
	t_list_item		*next;
	void			*data;
};

struct			s_list
{
	t_list_item		*head;
	t_list_item		*tail;
	size_t			size;
};

t_list_item		*list_item_create(void);
void			list_item_destroy(t_list_item **aself);

t_list			*list_create(void);
void			list_destroy(t_list **aself);

void			list_clean(t_list *self, void (*delf)());

int				list_pop_front(t_list *self, void **adata);
void			list_push_back(t_list *self, void *data);
void			list_push_front(t_list *self, void *data);

int				list_foreach(t_list *self, int (*foreachf)(), void *context);

#endif
