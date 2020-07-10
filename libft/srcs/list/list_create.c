/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:01:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 08:01:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_create(void)
{
	t_list		*self;

	self = (t_list *)ft_xmemalloc(sizeof(t_list));
	return (self);
}
