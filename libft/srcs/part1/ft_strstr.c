/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 03:21:06 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/21 23:29:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*p1;
	const char	*p2;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		p1 = haystack;
		p2 = needle;
		while (*p1++ == *p2++)
			if (!*p2)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
