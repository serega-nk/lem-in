/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:44:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 21:12:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "ft_xexit.h"

int		parse_int(char **addr, int *avalue);
int		parse_str(char **addr, char **avalue, const char *deny);
int		parse_skip(char **addr, const char *skip);
int		parse_goto(char **addr, const char *find);
int		parse_none(char **addr);

#endif
