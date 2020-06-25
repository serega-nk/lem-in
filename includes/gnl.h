/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:27:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/25 22:50:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_gnl	t_gnl;

struct	s_gnl
{
	int		fd;
};

t_gnl	*gnl_create(int fd);
void	gnl_destroy(t_gnl **aself);
int		gnl_readline(t_gnl *self, char **aline);

#endif
