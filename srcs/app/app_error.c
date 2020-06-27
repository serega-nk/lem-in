/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:46:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 14:26:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_error(t_app *self)
{
	if (self)
		ft_printf("ERROR\n");
	ft_xexit(EXIT_SUCCESS);
	//ft_xexit(EXIT_FAILURE);
}
