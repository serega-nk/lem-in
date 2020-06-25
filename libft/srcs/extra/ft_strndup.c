/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 04:41:00 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/06 01:28:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t maxsize)
{
	char		*dst;
	size_t		len;

	len = ft_strnlen(src, maxsize);
	dst = ft_strnew(len);
	if (dst)
		ft_strncpy(dst, src, len);
	return (dst);
}
