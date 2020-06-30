/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 06:02:49 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/19 06:03:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

void	*ft_xcheck(void *ptr)
{
	if (!ptr)
	{
		ft_printf_fd(STDERR_FILENO, "\nout of memory\n");
		ft_xexit(EXIT_FAILURE);
	}
	return (ptr);
}
