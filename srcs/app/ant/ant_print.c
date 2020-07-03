/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:31:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/03 19:39:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_print(t_ant *self, int index)
{
	if (self && self->curr)
	{
		ft_printf("%sL%d-%s", index ? " " : "", self->id, self->curr->name);
	}	
}
