/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:44:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 17:56:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"

int		parse_int(char **addr, int *avalue);
int		parse_str(char **addr, char **avalue, const char *stop);
int		parse_skip(char **addr, const char *skip);
int		parse_none(char **addr);

#endif
