/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 02:34:32 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 05:03:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (size > 0 && *dst)
	{
		size--;
		len++;
		dst++;
	}
	if (size > 0)
	{
		size--;
		ft_memcpy(dst, src, size);
		dst[size] = '\0';
	}
	return (len + ft_strlen(src));
}
