/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:30:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 13:43:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	gnl_destroy(t_gnl **aself)
{
	if (aself && *aself)
	{
		while ((*aself)->save[0])
		{
			ft_memdel((void **)&(*aself)->save[0]);
			(*aself)->save++;
		}
		ft_memdel((void **)&(*aself)->addr);
		ft_memdel((void **)aself);
	}
}