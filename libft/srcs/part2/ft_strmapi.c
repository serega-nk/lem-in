/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:16:52 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/06 22:24:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	char			*ptr;

	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (res)
	{
		i = 0;
		ptr = res;
		while (*ptr)
		{
			*ptr = (*f)(i++, *ptr);
			ptr++;
		}
	}
	return (res);
}
