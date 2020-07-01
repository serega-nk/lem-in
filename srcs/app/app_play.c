/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_play.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:07:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/01 20:49:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef struct s_ant	t_ant;

struct	s_ant
{
	int		id;
	t_room	*curr;
	t_room	*next;
};

t_ant	*ant_create(int id, t_room *first)
{
	t_ant	*self;

	self = (t_ant *)ft_xmemalloc(sizeof(t_ant));
	self->id = id;
	self->curr = NULL;
	self->next = first;
	return (self);
}

void	ant_destroy(t_ant **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}

void	*deque_remove(t_deque *self, t_deque_item *item)
{
	void	*data;

	data = NULL;
	if (self && item)
	{
		if (self->head == item)
			data = deque_pop_front(self);
		else if (self->tail == item)
			data = deque_pop_back(self);
		else
		{
			data = item->data;
			item->prev->next = item->next;
			item->next->prev = item->prev;
			deque_item_destroy(&item);
			self->size--;
		}
	}
	return (data);
}

void	app_play(t_app *self)
{
	//t_room		*room;
	//t_queue		*route;
	
	// route = queue_create();
	// if (hashtab_get(self->rooms, "2", (void **)&room))
	// 	queue_push_back(route, room);
	// if (hashtab_get(self->rooms, "3", (void **)&room))
	// 	queue_push_back(route, room);
	// queue_push_back(route, self->room_end);

	t_room *r0, *r1, *r2, *r3, *r42, *r21;
	r0 = r42 = NULL;
	if (hashtab_get(self->rooms, "0", (void **)&r0) &&
		hashtab_get(self->rooms, "1", (void **)&r1) &&
		hashtab_get(self->rooms, "2", (void **)&r2) &&
		hashtab_get(self->rooms, "3", (void **)&r3) && 
		hashtab_get(self->rooms, "42", (void **)&r42) &&
		hashtab_get(self->rooms, "21", (void **)&r21))
	{
		r0->path = r1;
		r1->path = r2;
		r2->path = r3;
		r42->path = r21;
		r21->path = r3;
	}

	t_deque *ants = deque_create();
	deque_push_back(ants, ant_create(1, r0));
	deque_push_back(ants, ant_create(2, r0));
	deque_push_back(ants, ant_create(3, r0));
	deque_push_back(ants, ant_create(4, r42));	
	deque_push_back(ants, ant_create(5, r42));
	deque_push_back(ants, ant_create(6, r42));
	
	// t_ant *a = (t_ant *)deque_remove(ants, ants->head);
	// ft_printf("REMOVE ant = %d [%d]\n", a->id, ants->size);

	while (ants->head)
	{
		//ft_printf("ants->size = %d  (%p)\n", ants->size, ants->head);
		int count = 0;
		t_deque_item *walk = ants->head;
		while (walk)
		{
			t_deque_item *item = walk;			
			t_ant *ant = (t_ant *)walk->data;
			walk = walk->next;

			if (ant->next && ant->next->lock == 0)
			{
				if (ant->curr)
					ant->curr->lock = 0;
				ant->curr = ant->next;
				ant->next = ant->curr->path;
				if (ant->next)
					ant->curr->lock = 1;
				ft_printf("%sL%d-%s", count == 0 ? "" : " ", ant->id, ant->curr->name);
				count++;
			}
			if (!ant->next)
			{
				deque_remove(ants, item);
				ant_destroy(&ant);
			}

		}
		ft_printf("\n");
		
	}

	// t_ant *ant = (t_ant *)ants->head->data;
	// while (ant->curr) {
	// 	room = (t_room *)ant->curr->data;
	// 	if ()
	// 	ft_printf("curr %s\n", room->name);
	// 	ant->curr = ant->curr->next;
	// }

	// //ft_printf_set_global_buffer(1024);
	// while ((self->line = queue_pop_front(self->lines)))
	// {
	// 	ft_printf("%s", self->line);
	// 	ft_strdel(&self->line);
	// }
	// ft_printf("\n");
	// ft_printf("### PLAY\n");
	// ft_printf("### ROOM START: %s, ROOM END: %s\n",
	// 	self->room_start->name, self->room_end->name);
	// //ft_printf_set_global_buffer(0);

	// t_hashtab_item	*item;
	// hashtab_start(self->room_start->links);
	// while ((item = hashtab_next(self->room_start->links)))
	// {
	// 	//room = (t_room *)item->value;
	// 	//ft_printf("START: key = %s, room = %s\n", item->key, ((t_room *)item->value)->name);
	// }

	// t_room		*room;
	// hashtab_start(self->room_end->links);
	// while (hashtab_next_kv(self->room_end->links, NULL, (void **)&room))
	// {
	// 	//ft_printf("END: link = %s\n", room->name);
	// }

	// t_heap	*heap;
	
	// heap = heap_create();
	
	// //ft_printf("HEAP COUNT = %llu, SIZE = %llu\n", heap->count, heap->size);
	
	// //int		ret = 0;
	// size_t	prio = 0;
	// char	*data = NULL;

	// //ret = heap_extract(heap, &prio, (void **)&data);
	// //ft_printf("***COUNT = %llu, RET = %llu, prio = %llu\n", heap->count, ret, prio);

	// heap_insert(heap, 6, ft_xstrdup("6"));
	// heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));
	// heap_insert(heap, 5, ft_xstrdup("5"));

	// while (heap_extract(heap, &prio, (void **)&data))
	// {
	//  	//ft_printf("***COUNT = %llu, prio = %llu, %s\n", heap->count, prio, data);
	//  	ft_strdel(&data);
	// }
	// heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));
	// heap_insert(heap, 5, ft_xstrdup("5"));
	// heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));
	// heap_insert(heap, 5, ft_xstrdup("5"));
	// heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));
	// heap_insert(heap, 5, ft_xstrdup("5"));

	// 	heap_insert(heap, 2, ft_xstrdup("2"));
	// heap_insert(heap, 1, ft_xstrdup("1"));
	// heap_insert(heap, 3, ft_xstrdup("3"));
	// heap_insert(heap, 4, ft_xstrdup("4"));
	// heap_insert(heap, 5, ft_xstrdup("5"));
	// while (heap_extract(heap, &prio, (void **)&data))
	// {
	//  	//ft_printf("***COUNT = %llu, prio = %llu, %s\n", heap->count, prio, data);
	//  	ft_strdel(&data);
	// }
	// // heap_insert(heap, 8, ft_xstrdup("8"));

	// // ret = heap_extract(heap, &prio, (void **)&data);
	// // ft_printf("COUNT = %llu, RET = %llu, prio = %llu, data = %s\n", heap->count, ret, prio, data);


	// // heap_insert(heap, 2, ft_xstrdup("2"));
	// // heap_insert(heap, 5, ft_xstrdup("5"));
	// // heap_insert(heap, 3, ft_xstrdup("3"));
	// // heap_insert(heap, 4, ft_xstrdup("4"));

	// // ret = heap_extract(heap, &prio, (void **)&data);
	// // ft_printf("COUNT = %llu, RET = %llu, prio = %llu, data = %s\n", heap->count, ret, prio, data);
	// // ft_strdel(&data);

	// //ft_printf("HEAP COUNT = %llu, SIZE = %llu\n", heap->count, heap->size);

	// heap_clean(heap, &ft_strdel);
	// heap_destroy(&heap);
}
