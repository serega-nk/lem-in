/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xexit_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:15:37 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/18 13:07:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

t_xexit	*ft_xexit_global(void)
{
	static t_xexit	save;
	static int		zero = 0;

	if (zero == 0)
	{
		ft_bzero(&save, sizeof(t_xexit));
		zero = 1;
	}
	return (&save);
}
