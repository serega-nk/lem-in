/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:11:35 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/07 05:33:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_strsplit_recursive(char const *s, char c, int index)
{
	char	**res;
	int		len;

	if (!*s)
		return (char **)ft_memalloc((index + 1) * sizeof(char *));
	while (*s == c)
		s++;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	res = ft_strsplit_recursive(s + len, c, index + (len > 0 ? 1 : 0));
	if (res && len > 0)
	{
		res[index] = ft_strsub(s, 0, len);
		if (!res[index])
		{
			index++;
			while (res[index])
				ft_strdel(&res[index++]);
			free(res);
			res = NULL;
		}
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_strsplit_recursive(s, c, 0));
	return (NULL);
}
