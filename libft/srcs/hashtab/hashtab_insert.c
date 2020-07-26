/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:38:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:57:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_bool	hashtab_insert(t_hashtab *self, const char *key, void *value)
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
				return (FALSE);
			awalk = &(*awalk)->next;
		}
		*awalk = hashtab_item_create(key, value);
		self->count++;
		return (TRUE);
	}
	return (FALSE);
}
