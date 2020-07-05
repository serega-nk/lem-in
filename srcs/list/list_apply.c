/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:38:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/05 04:52:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int		list_apply(t_list *self, int (*applyf)())
{
	t_list_item		**awalk;
	t_list_item		*next;
	int				ret;

	if (self)
	{
		awalk = &self->head;
		while (*awalk)
		{
			ret = (*applyf)(&(*awalk)->data);
			if (ret == 0)
				return (0);
			else if (ret == -1)
			{
				next = (*awalk)->next;
				list_item_destroy(awalk);
				*awalk = next;
			}
			else
				awalk = &(*awalk)->next;
		}
		return (1);
	}
	return (0);
}
