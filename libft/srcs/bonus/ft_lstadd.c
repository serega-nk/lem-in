/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 07:58:22 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/08 09:27:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (alst && new)
	{
		ptr = new;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = *alst;
		*alst = new;
	}
}
