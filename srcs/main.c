/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:26:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 23:00:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	test1(void)
{
	t_queue		*queue;

	queue = queue_create();
	ft_printf("PUSH [A, B, C]\n");
	queue_push_back(queue, "A");
	queue_push_back(queue, "B");
	queue_push_back(queue, "C");
	ft_printf("SIZE = %llu\n", queue->size);
	ft_printf("POP %s\n", queue_pop_front(queue));
	ft_printf("POP %s\n", queue_pop_front(queue));
	ft_printf("POP %s\n", queue_pop_front(queue));
	ft_printf("POP %s\n", queue_pop_front(queue));
	queue_destroy(&queue);
	ft_printf("=== EXIT\n");
}

void	test2(void)
{
	ft_printf("123\n");
}

int		main(void)
{
	test2();
	return (EXIT_SUCCESS);
}
