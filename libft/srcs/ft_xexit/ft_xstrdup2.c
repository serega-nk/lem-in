/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:31:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/18 16:31:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

char		*ft_xstrdup2(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)ft_xcheck((void *)ft_strnew(len1 + len2));
	ft_strncpy(res, s1, len1);
	ft_strncpy(res + len1, s2, len2);
	return (res);
}
