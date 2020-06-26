/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:26:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 05:51:01 by bconchit         ###   ########.fr       */
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
	ft_printf("PUSH [Z, X]\n");
	queue_push_back(queue, "Z");
	queue_push_back(queue, "X");
	ft_printf("POP %s\n", queue_pop_front(queue));
	ft_printf("SIZE = %llu\n", queue->size);
	ft_printf("CLEAN\n");
	queue_clean(queue);
	ft_printf("SIZE = %llu\n", queue->size);
	ft_printf("POP %s\n", queue_pop_front(queue));
	queue_push_back(queue, "E");
	queue_destroy(&queue);
	ft_printf("=== EXIT\n");
	//malloc(10);
}

void	test2(void)
{
	ft_printf("123\n");
}

int		main(void)
{
	test1();
	return (EXIT_SUCCESS);
}
