/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:26:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/03 19:34:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_app	app;

	ft_bzero(&app, sizeof(t_app));
	ft_on_xexit(&app_free, &app);
	app_load(&app);
	app_calc(&app);
	app_print(&app);
	app_free(&app);
	return (EXIT_SUCCESS);
}
