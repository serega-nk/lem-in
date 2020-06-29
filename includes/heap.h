/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:04:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:07:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include "libft.h"
# include "ft_xexit.h"
# include "ft_printf.h"

typedef struct s_heap_item	t_heap_item;
typedef struct s_heap		t_heap;

struct		s_heap_item
{
	size_t	priority;
	void	*data;
};

struct		s_heap
{
	t_heap_item	*table;
	size_t		size;
	size_t		count;
};

t_heap		*heap_create(void);
void		heap_destroy(t_heap **aself);

void		heap_resize(t_heap *self);
void		heap_sift_up(t_heap *self, size_t index);
void		heap_sift_down(t_heap *self, size_t index);

void		heap_insert(t_heap *self, size_t priority, void *data);
int			heap_extracct(t_heap *self, size_t *apriority, void **adata);

#endif
