/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:30:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/19 17:21:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	gnl_destroy(t_gnl **aself)
{
	if (aself && *aself)
	{
		if ((*aself)->save)
		{
			while ((*aself)->save[0])
			{
				ft_memdel((void **)&(*aself)->save[0]);
				(*aself)->save++;
			}
		}
		ft_memdel((void **)&(*aself)->addr);
		ft_memdel((void **)aself);
	}
}
