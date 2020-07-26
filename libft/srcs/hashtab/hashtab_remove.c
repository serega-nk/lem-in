/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:11:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:57:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_bool	hashtab_remove(t_hashtab *self, const char *key, void **avalue)
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
				return (TRUE);
			}
			awalk = &(*awalk)->next;
		}
	}
	return (FALSE);
}
