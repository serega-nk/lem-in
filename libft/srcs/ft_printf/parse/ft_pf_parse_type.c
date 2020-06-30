/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:22:15 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_pf_parse_type(t_parse *self)
{
	self->fmt.type = self->format[self->index];
	self->index++;
	return (1);
}
