/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:21:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:56:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTAB_H
# define HASHTAB_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_hashtab_item	t_hashtab_item;
typedef struct s_hashtab		t_hashtab;

struct			s_hashtab_item
{
	t_hashtab_item	*next;
	const char		*key;
	void			*value;
};

struct			s_hashtab
{
	t_hashtab_item	**table;
	size_t			size;
	size_t			count;
	size_t			curr;
	t_hashtab_item	*cursor;
};

t_hashtab		*hashtab_create(void);
void			hashtab_destroy(t_hashtab **aself);
void			hashtab_clean(t_hashtab *self, void (*delf)());

t_hashtab_item	*hashtab_item_create(const char *key, void *value);
void			hashtab_item_destroy(t_hashtab_item **aself);

size_t			hashtab_hash(const char *key, size_t size);

t_bool			hashtab_get(t_hashtab *self, const char *key, void **avalue);
t_bool			hashtab_insert(t_hashtab *self, const char *key, void *value);
t_bool			hashtab_remove(t_hashtab *self, const char *key, void **avalue);
void			hashtab_resize(t_hashtab *self);

void			hashtab_start(t_hashtab *self);
t_hashtab_item	*hashtab_next(t_hashtab *self);
t_bool			hashtab_next_kv(
	t_hashtab *self, const char **akey, void **avalue);

#endif
