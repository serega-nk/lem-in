/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:48:19 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/05 00:21:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				res;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	res = 0;
	while (n-- > 0 && !(res = (int)(*p1++ - *p2++)))
		;
	return (res);
}
