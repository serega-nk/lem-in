/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:04:37 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:58:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_pf_parse_width(t_parse *self)
{
	int		save;
	int		temp;

	self->fmt.width = -1;
	if (self->format[self->index] == '*')
	{
		self->index++;
		self->fmt.width = (int)va_arg(self->ap, int);
		if (self->fmt.width < 0)
		{
			self->fmt.minus = 1;
			self->fmt.width *= -1;
		}
	}
	save = self->index;
	temp = ft_pf_parse_number(self);
	if (save != self->index)
		self->fmt.width = temp;
	return (1);
}
