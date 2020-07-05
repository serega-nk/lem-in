/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 07:43:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 15:10:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_foreach(t_list *self, int (*foreachf)(), void *context)
{
	t_list_item		**awalk;
	t_list_item		*save;
	int				ret;

	if (self && foreachf)
	{
		awalk = &self->head;
		while (*awalk)
		{
			ret = (*foreachf)(context, (*awalk)->data);
			if (ret == LIST_FOREACH_STOP)
				return (0);
			else if (ret == LIST_FOREACH_REMOVE)
			{
				save = (*awalk)->next;
				list_item_destroy(awalk);
				*awalk = save;
			}
			else
				awalk = &(*awalk)->next;
		}
		return (1);
	}
	return (0);
}
