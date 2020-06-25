/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:30:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 22:42:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	gnl_destroy(t_gnl **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}