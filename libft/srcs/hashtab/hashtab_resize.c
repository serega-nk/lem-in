/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 20:35:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:19:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

static void		resize(t_hashtab *self, t_hashtab_item **table, size_t size)
{
	t_hashtab_item	*item;
	size_t			hash;
	size_t			i;

	self->size = size * 4;
	self->table = (t_hashtab_item **)
		ft_xmemalloc(self->size * sizeof(t_hashtab_item *));
	i = 0;
	while (i < size)
	{
		while (table[i])
		{
			item = table[i];
			table[i] = item->next;
			hash = hashtab_hash(item->key, self->size);
			item->next = self->table[hash];
			self->table[hash] = item;
		}
		i++;
	}
	ft_memdel((void **)&table);
}

void			hashtab_resize(t_hashtab *self)
{
	if (self && self->count > self->size * 2)
		resize(self, self->table, self->size);
}
