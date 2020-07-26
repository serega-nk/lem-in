/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:44:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/07/26 11:50:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "ft_xexit.h"

t_bool	parse_int(char **addr, int *avalue);
t_bool	parse_str(char **addr, char **avalue, const char *deny);
t_bool	parse_skip(char **addr, const char *skip);
t_bool	parse_goto(char **addr, const char *find);
t_bool	parse_none(char **addr);

#endif
