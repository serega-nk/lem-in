/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:04:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:28:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include "libft.h"
# include "ft_xexit.h"
# include "ft_printf.h"

typedef struct s_heap	t_heap;

struct		s_heap
{
	size_t	size;
	size_t	count;
};

t_heap		*heap_create(void);
void		heap_destroy(t_heap **aself);

#endif
