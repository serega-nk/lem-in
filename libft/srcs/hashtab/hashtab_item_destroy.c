/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_item_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 21:18:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 00:22:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void	hashtab_item_destroy(t_hashtab_item **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)&(*aself)->key);
		ft_memdel((void **)aself);
	}
}
