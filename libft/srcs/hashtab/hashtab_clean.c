/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 02:52:20 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 04:38:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void	hashtab_clean(t_hashtab *self, void (*delf)())
{
	t_hashtab_item	*item;
	size_t			i;

	if (self)
	{
		i = 0;
		while (i < self->size)
		{
			while (self->table[i])
			{
				item = self->table[i];
				self->table[i] = item->next;
				if (delf)
					(*delf)(&item->value);
				hashtab_item_destroy(&item);
			}
			i++;
		}
	}
}
