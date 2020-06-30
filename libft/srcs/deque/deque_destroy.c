/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:23:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 09:08:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_destroy(t_deque **aself)
{
	if (aself && *aself)
	{
		deque_clean(*aself);
		ft_memdel((void **)aself);
	}
}
