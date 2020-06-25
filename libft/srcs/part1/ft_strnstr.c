/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 03:52:18 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 05:22:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr;
	size_t		len1;
	size_t		len2;

	ptr = haystack;
	len1 = 0;
	while (len-- > 0 && *ptr)
	{
		ptr++;
		len1++;
	}
	len2 = ft_strlen(needle);
	while (len1-- >= len2)
	{
		if (ft_memcmp(haystack, needle, len2) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
