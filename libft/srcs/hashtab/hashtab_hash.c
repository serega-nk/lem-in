/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 22:04:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/29 18:19:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

size_t	hashtab_hash(const char *key, size_t size)
{
	size_t	hash;

	hash = 0;
	while (*key)
		hash = *key++ + 31 * hash;
	return (hash % size);
}
