/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:26:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/17 18:26:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	link_destroy(t_link **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
