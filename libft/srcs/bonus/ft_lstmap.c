/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 07:59:28 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 05:51:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstmap_del(void *content, size_t content_size)
{
	if (content_size)
		content_size = 0;
	free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	**addr;

	result = NULL;
	addr = &result;
	if (f)
	{
		while (lst)
		{
			*addr = (*f)(lst);
			if (!*addr)
			{
				ft_lstdel(&result, &ft_lstmap_del);
				return (NULL);
			}
			addr = &(*addr)->next;
			lst = lst->next;
		}
	}
	return (result);
}
