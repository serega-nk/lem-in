/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:50:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_skip(char **addr, const char *skip)
{
	size_t	len;

	len = ft_strlen(skip);
	if (ft_strncmp(*addr, skip, len) == 0)
	{
		*addr += len;
		return (TRUE);
	}
	return (FALSE);
}
