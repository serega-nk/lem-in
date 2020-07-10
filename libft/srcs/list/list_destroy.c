/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 08:02:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 14:24:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_destroy(t_list **aself)
{
	if (aself && *aself)
	{
		list_clean(*aself, NULL);
		ft_memdel((void **)aself);
	}
}
