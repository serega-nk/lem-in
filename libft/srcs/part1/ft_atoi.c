/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 04:11:48 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 04:11:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long long	res;
	unsigned long long	prev;
	unsigned long long	negative;

	negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		negative = 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		prev = res;
		res = res * 10 + (*str++ - '0');
		if (res < prev || res > ((unsigned long long)INT64_MAX) + negative)
			return (negative ? 0 : -1);
	}
	return ((int)((negative ? -1 : 1) * res));
}
