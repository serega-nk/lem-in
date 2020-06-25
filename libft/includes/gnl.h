/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:27:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/02/25 07:38:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

int		gnl_readline(int fd, char **aline);
void	gnl_clean(int fd);
char	**gnl_split(char *str, char sep);

#endif
