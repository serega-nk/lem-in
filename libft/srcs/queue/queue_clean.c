/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:18:07 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/02 00:48:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_clean(t_queue *self, void (*delf)())
{
	void	*data;

	while (queue_pop_front(self, &data))
	{
		if (delf)
			(*delf)(&data);
	}
}
