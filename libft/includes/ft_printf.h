/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 01:26:08 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/25 05:20:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
char	*ft_printf_strnew(const char *format, ...);

#endif
