/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:31:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 17:27:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_print(t_ant *self)
{
	if (self && self->room)
		ft_printf("L%d-%s", self->id, self->room->name);
}
