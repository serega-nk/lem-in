/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:39:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 02:59:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void		hashtab_destroy(t_hashtab **aself)
{
	if (aself && *aself)
	{
		hashtab_clean(*aself, NULL);
		ft_memdel((void **)&(*aself)->table);
		ft_memdel((void **)aself);
	}
}
