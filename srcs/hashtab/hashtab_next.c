/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 06:02:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 06:41:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

t_hashtab_item	*hashtab_next(t_hashtab *self)
{
	t_hashtab_item	*item;

	if (self)
	{
		while (self->cursor == NULL)
		{
			if (self->curr + 1 >= self->size)
				return (NULL);
			self->cursor = self->table[++self->curr];
		}
		item = self->cursor;
		self->cursor = self->cursor->next;
		return (item);
	}
	return (NULL);	
}
