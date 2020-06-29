/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 06:01:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 06:06:18 by bconchit         ###   ########.fr       */
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
