/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:38:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 04:40:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_hashtab	*hashtab_create(void)
{
	t_hashtab	*self;

	self = (t_hashtab *)ft_xmemalloc(sizeof(t_hashtab));
	self->size = 2;
	self->table = (t_hashtab_item **) \
		ft_xmemalloc(self->size * sizeof(t_hashtab_item *));
	return (self);
}