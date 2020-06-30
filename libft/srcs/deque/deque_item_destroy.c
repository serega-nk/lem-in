/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_item_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:32:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 09:27:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_item_destroy(t_deque_item **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
