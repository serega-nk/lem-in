/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:16:37 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 22:00:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_print_string(t_parse *self)
{
	char	*string;
	int		length;

	string = (char *)va_arg(self->ap, char *);
	if (!string)
		string = "(null)";
	length = (int)ft_strlen(string);
	if (self->fmt.precision < 0 || self->fmt.precision > length)
		self->fmt.precision = length;
	self->fmt.width -= self->fmt.precision;
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	ft_pf_output_putnstr(self, string, self->fmt.precision);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}
