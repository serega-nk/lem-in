/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:38:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/04 13:38:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_clean(t_list *self, void (*delf)())
{
	void	*data;

	while (list_pop_front(self, &data))
	{
		if (delf)
			(*delf)(&data);
	}
}
