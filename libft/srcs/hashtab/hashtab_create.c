/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:38:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:19:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_hashtab	*hashtab_create(void)
{
	t_hashtab	*self;

	self = (t_hashtab *)ft_xmemalloc(sizeof(t_hashtab));
	self->size = 2;
	self->table = (t_hashtab_item **)
		ft_xmemalloc(self->size * sizeof(t_hashtab_item *));
	return (self);
}
