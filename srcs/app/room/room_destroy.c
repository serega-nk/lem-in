/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 05:58:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/30 04:18:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		hashtab_destroy(&(*aself)->links);
		ft_strdel(&(*aself)->name);
		ft_memdel((void **)aself);
	}
}
