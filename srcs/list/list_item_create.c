/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_item_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:45:56 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 13:46:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_item	*list_item_create(void)
{
	t_list_item		*self;

	self = (t_list_item *)ft_xmemalloc(sizeof(t_list_item));
	return (self);
}
