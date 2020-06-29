/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:18:07 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 05:44:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_clean(t_queue *self, void (*delf)())
{
	void	*data;

	while ((data = queue_pop_front(self)))
	{
		if (delf)
			(*delf)(&data);
	}
}
