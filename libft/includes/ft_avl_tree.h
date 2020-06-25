/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:21:26 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/27 18:59:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_TREE_H
# define FT_AVL_TREE_H

void	*ft_avl_tree(int (*cmpf)());
void	*ft_avl_tree_create(int (*cmpf)(), void *(*dupf)(), void (*delf)());
void	ft_avl_tree_destroy(void **addr);
int		ft_avl_tree_count(void *self);
void	ft_avl_tree_insert(void *self, void *data);
int		ft_avl_tree_replace(void *self, void *data);
void	ft_avl_tree_apply(void *self, void (*applyf)(), void *arg);
void	ft_avl_tree_start(void *self);
void	*ft_avl_tree_next(void *self);

#endif
