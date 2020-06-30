/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:53:48 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_pf_parse_number(t_parse *self)
{
	int		result;

	result = 0;
	while (ft_isdigit(self->format[self->index]))
	{
		result *= 10;
		result += self->format[self->index] - '0';
		self->index++;
	}
	return (result);
}
