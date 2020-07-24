/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 05:12:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 05:18:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	option_destroy(t_option **aself)
{
	if (aself && *aself)
	{
		heap_clean((*aself)->routes, &list_destroy);
		heap_destroy(&(*aself)->routes);
		ft_memdel((void **)aself);
	}
}
