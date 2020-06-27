/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:49:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 17:57:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_skip(char **addr, const char *skip)
{
	size_t	len;

	len = ft_strlen(skip);
	if (ft_strncmp(*addr, skip, len) == 0)
	{
		*addr += len;
		return (1);
	}
	return (0);
}
