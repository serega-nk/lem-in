/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:26:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/26 09:43:07 by bconchit         ###   ########.fr       */
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
	ssize_t	length;

	//ft_printf("=== GNL\n");
	gnl = gnl_create(STDIN_FILENO);
	while (gnl_readline(gnl, &line) > 0)
	{
		length = strlen(line);
		if (line[length - 1] != '\n')
		{
			ft_printf("=== ERROR NOT END LINE\n");
			ft_strdel(&line);
			break ;
		}

		//ft_printf("READLINE |%s|\n", line);
		if (ft_strcmp(line, "##start\n") == 0)
		{
			ft_printf("=== BLOCK START\n");
		}
		else if (ft_strcmp(line, "##end\n") == 0)
		{
			ft_printf("=== BLOCK END\n");
		}
		else if (*line == '#')
		{
			ft_printf("=== SKIP COMMENT\n");
		}
		else
		{
			ft_printf("%s", line);
		}
		ft_strdel(&line);
	}
	gnl_destroy(&gnl);	
	//ft_printf("===\n");
}

void	test3(void)
{
	t_deque		*deque;

	deque = deque_create();
	ft_printf("PUSH BACK [3, 4]\n");
	deque_push_back(deque, "3");
	deque_push_back(deque, "4");
	ft_printf("PUSH FRONT [2, 1]\n");
	deque_push_front(deque, "2");
	deque_push_front(deque, "1");
	ft_printf("SIZE = %llu\n", deque->size);
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("PUSH BACK [3, 4]\n");
	deque_push_back(deque, "3");
	deque_push_back(deque, "4");
	ft_printf("PUSH FRONT [2, 1]\n");
	deque_push_front(deque, "2");
	deque_push_front(deque, "1");
	ft_printf("SIZE = %llu\n", deque->size);
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("PUSH BACK [Z, X]\n");
	deque_push_back(deque, "Z");
	deque_push_back(deque, "X");
	ft_printf("PUSH FRONT [A, B]\n");
	deque_push_front(deque, "A");
	deque_push_front(deque, "B");
	ft_printf("SIZE = %llu\n", deque->size);
	ft_printf("CLEAN\n");
	deque_clean(deque);
	ft_printf("SIZE = %llu\n", deque->size);
	ft_printf("POP FRONT %s\n", deque_pop_front(deque));
	ft_printf("POP BACK %s\n", deque_pop_back(deque));
	ft_printf("PUSH BACK [E]\n");
	deque_push_back(deque, "E");
	ft_printf("PUSH FRONT [S]\n");
	deque_push_front(deque, "S");
	ft_printf("DESTROY\n");
	deque_destroy(&deque);
	ft_printf("===\n");
}

int		main(void)
{
	test3();
	return (EXIT_SUCCESS);
}
