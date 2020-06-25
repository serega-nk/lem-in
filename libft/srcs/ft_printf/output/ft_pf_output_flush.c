/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_flush.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:12:47 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/23 20:39:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_output_flush(t_parse *self)
{
	ssize_t		ret;

	if (self->count > 0)
	{
		if (self->fd == -1)
		{
			if (self->str)
				ft_memcpy(self->str + self->result, self->buff, self->count);
			ret = self->count;
		}
		else
			ret = write(self->fd, self->buff, self->count);
		if (ret > 0)
			self->result += (int)ret;
	}
	self->count = 0;
}
