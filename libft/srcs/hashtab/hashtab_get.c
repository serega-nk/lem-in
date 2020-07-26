/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 23:08:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:57:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_bool	hashtab_get(t_hashtab *self, const char *key, void **avalue)
{
	t_hashtab_item	**awalk;
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
				return (TRUE);
			}
			awalk = &(*awalk)->next;
		}
	}
	return (FALSE);
}
