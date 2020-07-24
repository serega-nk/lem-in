/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 04:21:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/25 00:40:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

char		*ft_xstrdup3(const char *s1, const char *s2, const char *s3)
{
	size_t	len1;
	size_t	len2;
	size_t	len3;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	res = (char *)ft_xcheck((void *)ft_strnew(len1 + len2 + len3));
	ft_strncpy(res, s1, len1);
	ft_strncpy(res + len1, s2, len2);
	ft_strncpy(res + len1 + len2, s3, len3);
	return (res);
}
