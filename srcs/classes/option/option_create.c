/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 05:10:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 19:00:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_option	*option_create(void)
{
	t_option	*self;

	self = (t_option *)ft_xmemalloc(sizeof(t_option));
	return (self);
}
