/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:26:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 06:58:29 by bconchit         ###   ########.fr       */
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
	ft_printf("===\n");
}

void	test2(void)
{
	t_gnl	*gnl;
	char	*line;

	ft_printf("=== GNL\n");
	gnl = gnl_create(STDIN_FILENO);
	while (gnl_readline(gnl, &line) > 0)
	{
		//ft_printf("READLINE |%s|\n", line);
		ft_printf("%s", line);
		ft_strdel(&line);
	}
	gnl_destroy(&gnl);	
	ft_printf("===\n");
}

int		main(void)
{
	test2();
	return (EXIT_SUCCESS);
}
