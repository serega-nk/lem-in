/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xexit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:50:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/21 04:21:39 by bconchit         ###   ########.fr       */
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
char	*ft_xstrdup2(const char *s1, const char *s2);
char	*ft_xstrdup3(const char *s1, const char *s2, const char *s3);
void	*ft_xmemdup(const void *src, size_t size);

#endif
