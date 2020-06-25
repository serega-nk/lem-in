/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 03:44:05 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 05:23:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*ptr;
	size_t		len;

	ptr = s1;
	len = 0;
	while (n-- > 0)
	{
		len++;
		if (!*ptr)
			break ;
		ptr++;
	}
	return (ft_memcmp(s1, s2, len));
}
