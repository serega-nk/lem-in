/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_putnstr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 04:24:35 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/08 21:56:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_pf_output_putnstr(t_parse *self, const char *s, int n)
{
	while (n-- > 0 && *s)
		ft_pf_output_putchar(self, *s++);
}
