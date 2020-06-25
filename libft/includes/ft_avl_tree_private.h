/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:46:21 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/27 18:58:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_TREE_PRIVATE_H
# define FT_AVL_TREE_PRIVATE_H

# include "libft.h"
# include "ft_xexit.h"

# define FT_AVL_TREE_STACK_SIZE 100

typedef struct	s_avl_node
{
	struct s_avl_node	*left;
	struct s_avl_node	*right;
	void				*data;
	int					bfactor;
}				t_avl_node;

typedef struct	s_avl_tree
{
	t_avl_node			*root;
	int					count;
	int					balance;
	int					(*cmpf)(void *, void *);
	void				*(*dupf)(void *);
	void				(*delf)(void **);
	t_avl_node			*last;
	t_avl_node			*stack[FT_AVL_TREE_STACK_SIZE];
	unsigned char		stack_level;
}				t_avl_tree;

t_avl_tree		*ft_avl_tree_create
	(int (*cmpf)(), void *(*dupf)(), void (*delf)());
t_avl_node		*ft_avl_tree_node(t_avl_tree *self, void *data);
t_avl_node		*ft_avl_tree_balance(t_avl_tree *self, t_avl_node *walk);

#endif
