/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:49:55 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:56:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline int	check(t_parse *self, const char *find, const char *replace)
{
	const char	*ptr;
	size_t		len;

	ptr = &self->format[self->index];
	len = ft_strlen(find);
	if (ft_memcmp(ptr, find, len) == 0)
	{
		ft_pf_output_putstr(self, replace);
		self->index += len;
		return (1);
	}
	return (0);
}

void				ft_pf_parse_color(t_parse *self)
{
	if (check(self, "{red}", "\033[0;31m") ||
		check(self, "{green}", "\033[0;32m") ||
		check(self, "{brown}", "\033[0;33m") ||
		check(self, "{yellow}", "\033[1;33m") ||
		check(self, "{blue}", "\033[0;34m") ||
		check(self, "{purple}", "\033[0;35m") ||
		check(self, "{cyan}", "\033[0;36m") ||
		check(self, "{eoc}", "\033[0m"))
		;
	else
		ft_pf_parse_next(self);
}
