/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:05:58 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:45:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_destroy(t_heap **aself)
{
	if (aself && *aself)
	{
		ft_printf("DESTROY HEAP count = %llu, size = %llu\n", (*aself)->count, (*aself)->size);
		ft_memdel((void **)&(*aself)->table);
		ft_memdel((void **)aself);
	}
}
