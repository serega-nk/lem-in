/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xexit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:50:47 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/21 19:15:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XEXIT_H
# define FT_XEXIT_H

# include <stdlib.h>

void	ft_on_xexit(void (*function)(), void *arg);
void	ft_xexit(int status);
void	*ft_xmalloc(size_t size);
void	*ft_xmemalloc(size_t size);
void	*ft_xcheck(void *ptr);
char	*ft_xstrdup(const char *s1);

#endif
