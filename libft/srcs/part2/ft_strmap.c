/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:09:26 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/06 22:16:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*ptr;

	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (res)
	{
		ptr = res;
		while (*ptr)
		{
			*ptr = (*f)(*ptr);
			ptr++;
		}
	}
	return (res);
}
