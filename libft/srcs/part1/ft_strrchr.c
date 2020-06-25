/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 03:03:22 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/05 04:10:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ptr = ft_strchr(s, 0);
	if (ptr)
	{
		ch = (char)c;
		while (s <= ptr)
		{
			if (*ptr == ch)
				return (ptr);
			ptr--;
		}
	}
	return (NULL);
}
