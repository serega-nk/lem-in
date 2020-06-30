/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 21:16:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 05:43:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_destroy(t_queue **aself)
{
	if (aself && *aself)
	{
		queue_clean(*aself, NULL);
		ft_memdel((void **)aself);
	}
}
