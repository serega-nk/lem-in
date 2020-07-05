/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_item_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:46:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 13:46:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_item_destroy(t_list_item **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
