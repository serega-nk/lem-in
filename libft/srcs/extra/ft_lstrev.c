/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 09:04:30 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/05 05:36:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*list;
	t_list	*next;
	t_list	*prev;

	list = *alst;
	prev = NULL;
	while (list)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}
	*alst = prev;
}
