/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_goto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:30:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 18:37:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_goto(char **addr, const char *find)
{
	char	*ptr;
	size_t	len;

	ptr = *addr;
	len = ft_strlen(find);
	while (*ptr)
	{
		if (ft_strncmp(ptr, find, len) == 0)
		{
			*addr = ptr + len;
			return (1);
		}
		ptr++;
	}
	return (0);
}
