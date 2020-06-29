/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:55:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 21:08:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_str(char **addr, char **avalue, const char *deny)
{
	char	*ptr;

	ptr = *addr;
	while (*ptr)
	{
		if (ft_strchr(deny, *ptr))
			break ;
		ptr++;
	}
	if (ptr > *addr)
	{
		*avalue = (char *)ft_xcheck((void *)ft_strndup(*addr, ptr - *addr));
		*addr = ptr;
		return (1);
	}
	return (0);
}