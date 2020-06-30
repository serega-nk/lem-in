/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 05:32:46 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:57:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline int	check(t_parse *self, char type, void (*func)())
{
	if (self->fmt.type == type)
	{
		(*func)(self);
		return (1);
	}
	return (0);
}

int					ft_pf_parse_print(t_parse *self)
{
	if (check(self, 'c', &ft_pf_print_char) ||
		check(self, 's', &ft_pf_print_string) ||
		check(self, 'p', &ft_pf_print_hex) ||
		check(self, 'd', &ft_pf_print_signed) ||
		check(self, 'i', &ft_pf_print_signed) ||
		check(self, 'o', &ft_pf_print_octal) ||
		check(self, 'u', &ft_pf_print_unsigned) ||
		check(self, 'x', &ft_pf_print_hex) ||
		check(self, 'X', &ft_pf_print_hex) ||
		check(self, 'f', &ft_pf_print_double) ||
		check(self, '%', &ft_pf_print_escape) ||
		check(self, 'b', &ft_pf_print_binary) ||
		check(self, 'k', &ft_pf_print_date))
		return (1);
	return (0);
}
