/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:19:24 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/06 20:07:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	cc;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	cc = (unsigned char)c;
	while (n-- > 0)
	{
		if ((*d++ = *s++) == cc)
			return (d);
	}
	return (NULL);
}
