/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:16:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 14:15:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_destroy(t_queue **aself)
{
	if (aself && *aself)
	{
		queue_clean(*aself);
		ft_memdel((void **)aself);
	}
}
