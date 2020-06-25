/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:28:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/29 13:09:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_PRIVATE_H
# define GNL_PRIVATE_H

# include <unistd.h>
# include "libft.h"
# include "ft_xexit.h"

# define GNL_FDS 1000
# define GNL_BUF 1000

typedef struct	s_gnl
{
	char		**addr;
	char		**save;
	int			eof;
}				t_gnl;

t_gnl			*gnl_state(int fd);
char			**gnl_split(char *str, char sep);

#endif
