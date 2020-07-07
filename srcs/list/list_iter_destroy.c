/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:02:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 22:02:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_iter_destroy(t_list_iter **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
