/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:25:10 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 08:09:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1);
	if (size >= SIZE_MAX)
		return (NULL);
	size++;
	result = (char *)malloc(size * sizeof(char));
	if (result)
		ft_memcpy(result, s1, size);
	return (result);
}
