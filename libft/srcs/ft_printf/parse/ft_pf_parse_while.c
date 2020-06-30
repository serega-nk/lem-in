/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:22:43 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_parse_while(t_parse *self)
{
	char	ch;

	if (ft_strequ(self->format, "%"))
		return ;
	while ((ch = self->format[self->index]))
	{
		if (ch == '%')
			ft_pf_parse_format(self);
		else if (ch == '{')
			ft_pf_parse_color(self);
		else
			ft_pf_parse_next(self);
	}
	ft_pf_output_flush(self);
}
