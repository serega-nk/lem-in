/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 20:41:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	app_play(t_app *self)
{
	//ft_printf_set_global_buffer(1024);
	while ((self->line = queue_pop_front(self->lines)))
	{
		ft_printf("%s", self->line);
		ft_strdel(&self->line);
	}
	ft_printf("\n");
	ft_printf("### PLAY\n");
	ft_printf("### ROOM START: %s, ROOM END: %s\n",
		self->room_start->name, self->room_end->name);
	//ft_printf_set_global_buffer(0);

	t_hashtab_item	*item;
	hashtab_start(self->room_start->links);
	while ((item = hashtab_next(self->room_start->links)))
	{
		//room = (t_room *)item->value;
		ft_printf("START: key = %s, room = %s\n", item->key, ((t_room *)item->value)->name);
	}

	t_room		*room;
	hashtab_start(self->room_end->links);
	while (hashtab_next_kv(self->room_end->links, NULL, (void **)&room))
	{
		ft_printf("END: link = %s\n", room->name);
	}

	t_heap	*heap;
	
	heap = heap_create();
	
	ft_printf("HEAP COUNT = %llu, SIZE = %llu\n", heap->count, heap->size);
	
	int		ret = 0;
	size_t	prio = 0;
	char	*data = NULL;

	ret = heap_extract(heap, &prio, (void **)&data);
	ft_printf("COUNT = %llu, RET = %llu, prio = %llu\n", heap->count, ret, prio);

	heap_insert(heap, 10, ft_xstrdup("10"));
	heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 5, ft_xstrdup("5"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));

	ret = heap_extract(heap, &prio, (void **)&data);
	ft_printf("COUNT = %llu, RET = %llu, prio = %llu, data = %s\n", heap->count, ret, prio, data);
	ft_strdel(&data);
	
	// heap_insert(heap, 8, ft_xstrdup("8"));

	// ret = heap_extract(heap, &prio, (void **)&data);
	// ft_printf("COUNT = %llu, RET = %llu, prio = %llu, data = %s\n", heap->count, ret, prio, data);


	heap_insert(heap, 2, ft_xstrdup("2"));
	heap_insert(heap, 5, ft_xstrdup("5"));
	heap_insert(heap, 3, ft_xstrdup("3"));
	heap_insert(heap, 4, ft_xstrdup("4"));

	ret = heap_extract(heap, &prio, (void **)&data);
	ft_printf("COUNT = %llu, RET = %llu, prio = %llu, data = %s\n", heap->count, ret, prio, data);
	ft_strdel(&data);

	ft_printf("HEAP COUNT = %llu, SIZE = %llu\n", heap->count, heap->size);

	heap_clean(heap, &ft_strdel);
	heap_destroy(&heap);	
}
