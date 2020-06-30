/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_next_kv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 06:02:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 06:22:40 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

int		hashtab_next_kv(t_hashtab *self, const char **akey, void **avalue)
{
	t_hashtab_item	*item;

	item = hashtab_next(self);
	if (item)
	{
		if (akey)
			*akey = item->key;
		if (avalue)
			*avalue = item->value;
		return (1);
	}
	return (0);
}
