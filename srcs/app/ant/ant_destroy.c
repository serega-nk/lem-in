/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:30:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 22:13:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_destroy(t_ant **aself)
{
	if (aself && *aself)
	{
		list_iter_destroy(&(*aself)->iter);
		ft_memdel((void **)aself);
	}
}
