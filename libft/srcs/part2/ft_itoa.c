/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 05:32:38 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/07 21:36:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nn;
	int				len;
	int				sta;

	sta = ((n < 0) ? 1 : 0);
	len = sta + 1;
	nn = ((n < 0) ? (unsigned int)(-n) : (unsigned int)n);
	while (nn > 9)
	{
		nn /= 10;
		len++;
	}
	res = ft_strnew(len);
	if (res)
	{
		nn = ((n < 0) ? (unsigned int)(-n) : (unsigned int)n);
		while (len-- > 0)
		{
			res[len] = ((len < sta) ? '-' : '0' + nn % 10);
			nn /= 10;
		}
	}
	return (res);
}
