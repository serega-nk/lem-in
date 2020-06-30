/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:28:01 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 22:02:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline double long			get_value(t_parse *self)
{
	double long		result;

	if (self->fmt.length == LENGTH_CAP_L)
		result = (double long)va_arg(self->ap, double long);
	else
		result = (double long)va_arg(self->ap, double);
	return (result);
}

void								make(t_parse *self,
	unsigned long long part1, unsigned long long part2)
{
	int		length;

	length = 0;
	while (part2)
	{
		self->temp[length++] = '0' + (part2 % 10);
		part2 = part2 / 10;
	}
	while (length < self->fmt.precision)
		self->temp[length++] = '0';
	if (length > 0)
		self->temp[length++] = '.';
	if (part1 == 0)
		self->temp[length++] = '0';
	while (part1)
	{
		self->temp[length++] = '0' + (part1 % 10);
		part1 = part1 / 10;
	}
	self->temp[length] = '\0';
}

static inline void					output(t_parse *self, char sign)
{
	int		length;

	length = (int)ft_strlen(self->temp);
	if (sign)
		self->fmt.width -= 1;
	self->fmt.width -= length;
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	if (sign)
		ft_pf_output_putchar(self, sign);
	while (length-- > 0)
		ft_pf_output_putchar(self, self->temp[length]);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}

static inline unsigned long long	power10(int n)
{
	unsigned long long	result;

	result = 1;
	while (n-- > 0)
		result *= 10;
	return (result);
}

void								ft_pf_print_double(t_parse *self)
{
	double long			value;
	char				sign;
	unsigned long long	part1;
	unsigned long long	pow10;

	value = get_value(self);
	sign = '\0';
	if (self->fmt.space)
		sign = ' ';
	if (self->fmt.plus)
		sign = '+';
	if (value < 0)
		sign = '-';
	if (value < 0)
		value = -value;
	if (self->fmt.precision < 0)
		self->fmt.precision = 6;
	pow10 = power10(self->fmt.precision + 1);
	part1 = (unsigned long long)value;
	value = (value - (double long)part1) * (double long)pow10;
	value = ((unsigned long long)value % 10 > 4) ? value / 10 + 1 : value / 10;
	part1 += (unsigned long long)value / (pow10 / 10);
	make(self, part1, (unsigned long long)value % (pow10 / 10));
	output(self, sign);
}
