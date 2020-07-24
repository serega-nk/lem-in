/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 01:37:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/24 17:45:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int		ft_snprintf(char *str, size_t n, const char *format, ...)
{
	t_parse		self;

	ft_bzero(&self, sizeof(t_parse));
	if (format)
	{
		self.fd = -1;
		self.str = str;
		self.n = n;
		self.format = format;
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
	}
	return (self.result);
}
