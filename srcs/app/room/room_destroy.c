/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 05:58:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 05:59:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_destroy(t_room **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		hashtab_destroy(&(*aself)->links);
		ft_memdel((void **)aself);
	}
}
