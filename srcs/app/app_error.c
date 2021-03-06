/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 23:46:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 22:18:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_error(t_app *self)
{
	if (self)
		ft_printf_fd(STDERR_FILENO, "ERROR\n");
	ft_xexit(EXIT_FAILURE);
}
