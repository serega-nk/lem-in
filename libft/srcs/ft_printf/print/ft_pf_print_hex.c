/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:52:05 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:59:55 by bconchit         ###   ########.fr       */
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
									unsigned long long value, int big)
{
	if (value / 16 > 0)
		ptr = recursive(ptr, value / 16, big);
	if (big)
		*ptr = "0123456789ABCDEF"[value % 16];
	else
		*ptr = "0123456789abcdef"[value % 16];
	*(++ptr) = '\0';
	return (ptr);
}

static inline void					output(t_parse *self, char *string)
{
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	if (self->fmt.sharp)
	{
		ft_pf_output_putchar(self, '0');
		ft_pf_output_putchar(self, self->fmt.type == 'X' ? 'X' : 'x');
	}
	ft_pf_output_repeat(self, '0', self->fmt.precision);
	ft_pf_output_putstr(self, string);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}

void								ft_pf_print_hex(t_parse *self)
{
	unsigned long long	value;
	int					length;

	if (self->fmt.type == 'p')
		self->fmt.length = LENGTH_LL;
	value = get_value(self);
	*(self->temp) = '\0';
	if (!(self->fmt.precision == 0 && value == 0))
		recursive(self->temp, value, self->fmt.type == 'X');
	length = (int)ft_strlen(self->temp);
	if (!value)
		self->fmt.sharp = 0;
	if (self->fmt.type == 'p')
		self->fmt.sharp = 1;
	if (self->fmt.sharp)
		self->fmt.width -= 2;
	if (self->fmt.minus)
		self->fmt.zero = 0;
	if (self->fmt.precision < 0 && self->fmt.zero)
		self->fmt.precision = self->fmt.width;
	self->fmt.precision -= length;
	self->fmt.width -= length;
	if (self->fmt.precision > 0)
		self->fmt.width -= self->fmt.precision;
	output(self, self->temp);
}
