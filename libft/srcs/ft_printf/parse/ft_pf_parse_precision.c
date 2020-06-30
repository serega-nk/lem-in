/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:22:12 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_pf_parse_precision(t_parse *self)
{
	if (self->format[self->index] == '.')
	{
		self->index++;
		if (self->format[self->index] == '*')
		{
			self->index++;
			self->fmt.precision = (int)va_arg(self->ap, int);
		}
		else
		{
			self->fmt.precision = ft_pf_parse_number(self);
		}
	}
	else
	{
		self->fmt.precision = -1;
	}
	return (1);
}
