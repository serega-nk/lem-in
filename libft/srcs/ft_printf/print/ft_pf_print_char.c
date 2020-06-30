/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:23:46 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:58:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_print_char(t_parse *self)
{
	char	value;

	value = (char)va_arg(self->ap, int);
	if (self->fmt.minus)
		ft_pf_output_putchar(self, value);
	ft_pf_output_repeat(self, ' ', self->fmt.width - 1);
	if (!self->fmt.minus)
		ft_pf_output_putchar(self, value);
}
