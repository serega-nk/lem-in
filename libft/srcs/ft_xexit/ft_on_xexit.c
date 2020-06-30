/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_xexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:54:18 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 04:22:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

void	ft_on_xexit(void (*function)(), void *arg)
{
	t_xexit		*save;

	save = ft_xexit_global();
	save->function = function;
	save->arg = arg;
}
