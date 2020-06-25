/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 01:21:41 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/06 01:44:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *src, size_t maxsize)
{
	const char	*ptr;

	ptr = src;
	while (maxsize-- > 0 && *ptr)
		ptr++;
	return ((size_t)(ptr - src));
}
