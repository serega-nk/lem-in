/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_flush.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:12:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/24 17:57:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void			ft_pf_output_flush(t_parse *self)
{
	ssize_t		ret;
	size_t		count;

	if (self->count > 0)
	{
		if (self->str)
		{
			count = self->n < self->count ? self->n : self->count;
			if (count > 0)
			{
				self->n -= count;
				ft_memcpy(self->str + self->result, self->buff, count);
				self->str[self->result + count] = '\0';
			}
			self->result += self->count;
		}
		else if (self->fd == -1)
			self->result += self->count;
		else
		{
			if ((ret = write(self->fd, self->buff, self->count)) > 0)
				self->result += (int)ret;
		}
	}
	self->count = 0;
}
