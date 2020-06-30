/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xexit_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:50:47 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 04:20:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XEXIT_PRIVATE_H
# define FT_XEXIT_PRIVATE_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_xexit.h"

typedef struct	s_xexit
{
	void	(*function)();
	void	*arg;
}				t_xexit;

t_xexit			*ft_xexit_global(void);

#endif
