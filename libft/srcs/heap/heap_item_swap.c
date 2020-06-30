/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_item_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:45:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 23:07:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_item_swap(t_heap_item *item_a, t_heap_item *item_b)
{
	t_heap_item		temp;

	temp = *item_a;
	*item_a = *item_b;
	*item_b = temp;
}
