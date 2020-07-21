/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 05:58:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 05:05:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		ft_memdel((void **)aself);
	}
}
