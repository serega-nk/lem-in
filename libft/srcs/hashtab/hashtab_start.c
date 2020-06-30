/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 06:01:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:18:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void	hashtab_start(t_hashtab *self)
{
	if (self)
	{
		self->curr = 0;
		self->cursor = self->table[self->curr];
	}
}
