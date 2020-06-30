/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_item_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 21:17:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/28 23:05:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_hashtab_item	*hashtab_item_create(const char *key, void *value)
{
	t_hashtab_item		*self;

	self = (t_hashtab_item *)ft_xmemalloc(sizeof(t_hashtab_item));
	self->key = ft_xstrdup(key);
	self->value = value;
	return (self);
}
