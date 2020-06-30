/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 04:33:39 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline void	clean(t_parse *self)
{
	ft_bzero(&self->fmt, sizeof(t_fmt));
}

void				ft_pf_parse_format(t_parse *self)
{
	int		save;

	save = self->index;
	self->index++;
	clean(self);
	if (ft_pf_parse_flags(self) &&
		ft_pf_parse_width(self) &&
		ft_pf_parse_precision(self) &&
		ft_pf_parse_length(self) &&
		ft_pf_parse_type(self) &&
		ft_pf_parse_print(self))
		;
	else
	{
		self->index = save;
		ft_pf_parse_next(self);
	}
}
