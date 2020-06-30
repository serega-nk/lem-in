/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:28:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 22:54:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

t_gnl	*gnl_create(int fd)
{
	t_gnl	*self;

	self = (t_gnl *)ft_xmemalloc(sizeof(t_gnl));
	self->fd = fd;
	return (self);
}
