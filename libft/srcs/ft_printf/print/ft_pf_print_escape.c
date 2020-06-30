/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_escape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:28:01 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:59:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_print_escape(t_parse *self)
{
	if (self->fmt.minus)
		ft_pf_output_putchar(self, '%');
	ft_pf_output_repeat(self, ' ', self->fmt.width - 1);
	if (!self->fmt.minus)
		ft_pf_output_putchar(self, '%');
}
