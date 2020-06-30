/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:17:49 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 22:00:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline unsigned long long	get_value(t_parse *self)
{
	unsigned long long	result;

	if (self->fmt.length == LENGTH_LL)
		result = (unsigned long long)va_arg(self->ap, unsigned long long);
	else if (self->fmt.length == LENGTH_L)
		result = (unsigned long long)va_arg(self->ap, unsigned long);
	else if (self->fmt.length == LENGTH_HH)
		result = (unsigned long long)(unsigned char)\
			va_arg(self->ap, unsigned int);
	else if (self->fmt.length == LENGTH_H)
		result = (unsigned long long)(unsigned short)\
			va_arg(self->ap, unsigned int);
	else
		result = (unsigned long long)va_arg(self->ap, unsigned int);
	return (result);
}

static inline char					*recursive(char *ptr,
									unsigned long long value)
{
	if (value / 10 > 0)
		ptr = recursive(ptr, value / 10);
	*ptr = '0' + (value % 10);
	*(++ptr) = '\0';
	return (ptr);
}

void								ft_pf_print_unsigned(t_parse *self)
{
	unsigned long long	value;
	int					length;

	value = get_value(self);
	*(self->temp) = '\0';
	if (!(self->fmt.precision == 0 && value == 0))
		recursive(self->temp, value);
	length = (int)ft_strlen(self->temp);
	if (self->fmt.precision < 0 && self->fmt.zero)
		self->fmt.precision = self->fmt.width;
	self->fmt.precision -= length;
	self->fmt.width -= length;
	if (self->fmt.precision > 0)
		self->fmt.width -= self->fmt.precision;
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	ft_pf_output_repeat(self, '0', self->fmt.precision);
	ft_pf_output_putstr(self, self->temp);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}
