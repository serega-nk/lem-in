/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 02:44:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 17:48:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_int(char **addr, int *avalue)
{
	char	*ptr;
	long	prev;
	long	curr;
	int		negative;

	ptr = *addr;
	negative = (*ptr == '-' && ptr++) ? 1 : 0;
	if (ft_isdigit(*ptr))
	{
		if (*ptr == '0' && ft_isdigit(*(ptr + 1)))
			return (0);
		curr = 0;
		while (ft_isdigit(*ptr))
		{
			prev = curr;
			curr = curr * 10 + (*ptr++ - '0');
			if ((int)(curr - negative) < (int)(prev - negative))
				return (0);
		}
		*addr = ptr;
		*avalue = (int)(curr * (negative ? -1 : 1));
		return (1);
	}
	return (0);
}
