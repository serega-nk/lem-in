/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 07:57:47 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/09 03:00:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;

	if (alst && del && *alst)
	{
		ptr = *alst;
		(*del)(ptr->content, ptr->content_size);
		*alst = ptr->next;
		free(ptr);
	}
}
