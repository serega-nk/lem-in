/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:11:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 03:05:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

int		hashtab_remove(t_hashtab *self, const char *key, void **avalue)
{
	t_hashtab_item	**awalk;
	t_hashtab_item	*next;
	size_t			hash;

	if (self)
	{
		hash = hashtab_hash(key, self->size);
		awalk = &self->table[hash];
		while (*awalk)
		{
			if (ft_strcmp(key, (*awalk)->key) == 0)
			{
				if (avalue)
					*avalue = (*awalk)->value;
				next = (*awalk)->next;
				hashtab_item_destroy(awalk);
				*awalk = next;
				self->count--;
				return (1);
			}
			awalk = &(*awalk)->next;
		}
	}
	return (0);
}
