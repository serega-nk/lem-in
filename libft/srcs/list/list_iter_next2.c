/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter_next2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:42:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/07 22:12:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*list_iter_next2(t_list_iter *self)
{
	void	*data;

	data = NULL;
	list_iter_next(self, &data);
	return (data);
}
