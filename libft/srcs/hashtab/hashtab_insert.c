/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:38:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:18:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

int		hashtab_insert(t_hashtab *self, const char *key, void *value)
{
	t_hashtab_item	**awalk;
	size_t			hash;

	if (self)
	{
		hashtab_resize(self);
		hash = hashtab_hash(key, self->size);
		awalk = &self->table[hash];
		while (*awalk)
		{
			if (ft_strcmp(key, (*awalk)->key) == 0)
				return (0);
			awalk = &(*awalk)->next;
		}
		*awalk = hashtab_item_create(key, value);
		self->count++;
		return (1);
	}
	return (0);
}
