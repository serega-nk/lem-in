/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xexit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:48:22 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 04:20:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

void	ft_xexit(int status)
{
	t_xexit		*save;

	save = ft_xexit_global();
	if (save->function)
		(*save->function)(save->arg, status);
	exit(status);
}
