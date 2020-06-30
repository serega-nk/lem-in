/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:13:07 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline int	check(t_parse *self, char *sub, t_length value)
{
	int		index;

	index = 0;
	while (sub[index])
	{
		if (self->format[self->index + index] != sub[index])
			return (0);
		index++;
	}
	self->fmt.length = value;
	self->index += index;
	return (1);
}

int					ft_pf_parse_length(t_parse *self)
{
	if (check(self, "hh", LENGTH_HH) ||
		check(self, "ll", LENGTH_LL) ||
		check(self, "h", LENGTH_H) ||
		check(self, "l", LENGTH_L) ||
		check(self, "L", LENGTH_CAP_L))
		return (1);
	return (1);
}
