/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 05:06:30 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/25 05:20:10 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_printf.h"

char	*ft_printf_strnew(const char *format, ...)
{
	t_parse		self;
	char		*res;

	ft_bzero(&self, sizeof(t_parse));
	if (format)
	{
		self.fd = -1;
		self.str = NULL;
		self.format = format;
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
		if ((res = ft_strnew(self.result)))
		{
			ft_bzero(&self, sizeof(t_parse));
			self.fd = -1;
			self.str = res;
			self.format = format;
			va_start(self.ap, format);
			ft_pf_parse_while(&self);
			va_end(self.ap);
			return (res);
		}
	}
	return (NULL);
}
