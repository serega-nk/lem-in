/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:05:58 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 19:14:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

void	heap_destroy(t_heap **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)(*aself)->table);
		ft_memdel((void **)aself);
	}
}
