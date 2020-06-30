/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:04:33 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline int	check(t_parse *self, char flag, int *addr)
{
	if (self->format[self->index] == flag)
	{
		*addr = 1;
		self->index++;
		return (1);
	}
	return (0);
}

int					ft_pf_parse_flags(t_parse *self)
{
	while (check(self, '#', &self->fmt.sharp) ||
		check(self, '0', &self->fmt.zero) ||
		check(self, '-', &self->fmt.minus) ||
		check(self, '+', &self->fmt.plus) ||
		check(self, ' ', &self->fmt.space))
		;
	return (1);
}
