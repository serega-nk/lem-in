/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_putchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:11:24 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 22:54:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_output_putchar(t_parse *self, char c)
{
	if (self->count == FT_PRINTF_BUFF_SIZE)
		ft_pf_output_flush(self);
	self->buff[self->count] = c;
	self->count++;
}
