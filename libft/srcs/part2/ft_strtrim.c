/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 00:07:42 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/07 01:09:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_skip(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	while (ft_strtrim_skip(*s))
		s++;
	len = ft_strlen(s);
	while (len > 0 && ft_strtrim_skip(*(s + len - 1)))
		len--;
	str = ft_strnew(len);
	if (str)
		ft_strncpy(str, s, len);
	return (str);
}
