/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:35:28 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 08:09:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;

	if (len >= SIZE_MAX)
		return (NULL);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result)
	{
		index = 0;
		while (s && s[start] && len-- > 0)
			result[index++] = s[start++];
		result[index] = '\0';
	}
	return (result);
}
