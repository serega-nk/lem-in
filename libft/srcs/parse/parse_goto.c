/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_goto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 18:30:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:47:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_goto(char **addr, const char *find)
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
			return (TRUE);
		}
		ptr++;
	}
	return (FALSE);
}
