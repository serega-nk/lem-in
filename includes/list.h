/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:04:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 04:52:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft.h"
# include "ft_xexit.h"

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

int				list_apply(t_list *self, int (*applyf)());
void			list_clean(t_list *self, void (*delf)());

int				list_pop_front(t_list *self, void **adata);
void			list_push_back(t_list *self, void *data);
void			list_push_front(t_list *self, void *data);

#endif
