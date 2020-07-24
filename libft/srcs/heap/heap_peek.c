/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_peek.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 23:57:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 00:00:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	*heap_peek(t_heap *self)
{
	if (self && self->count > 0)
	{
		return (self->table->data);
	}
	return (NULL);
}
