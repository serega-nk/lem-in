/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:40:45 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/18 13:14:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		size = 1;
	ptr = malloc(size);
	if (!ptr)
	{
		ft_printf_fd(STDERR_FILENO,
			"\nout of memory allocating %lu bytes\n", (unsigned long)size);
		ft_xexit(EXIT_FAILURE);
	}
	return (ptr);
}
