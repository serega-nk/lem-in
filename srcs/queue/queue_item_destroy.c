/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_item_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:50:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 21:50:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_item_destroy(t_queue_item **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
