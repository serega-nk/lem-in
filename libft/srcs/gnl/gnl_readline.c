/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 22:27:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/06/27 21:06:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char		**gnl_split(char *str, char sep, int index)
{
	char	**res;
	int		len;

	if (!*str)
		return (char **)ft_xmemalloc((index + 1) * sizeof(char *));
	len = 0;
	while (str[len])
	{
		if (str[len++] == sep)
			break ;
	}
	res = gnl_split(str + len, sep, index + 1);
	res[index] = ft_strsub(str, 0, len);
	if (!res[index])
	{
		index++;
		while (res[index])
			ft_strdel(&res[index++]);
		ft_memdel((void **)&res);
		ft_xexit(EXIT_FAILURE);
	}
	return (res);
}

static int		gnl_pop(t_gnl *self, char **aline)
{
	if (self->save && self->save[0] &&
		(self->save[1] || self->eof || ft_strchr(self->save[0], '\n')))
	{
		*aline = self->save[0];
		self->save[0] = NULL;
		self->save++;
		return (1);
	}
	return (0);
}

static void		gnl_push(t_gnl *self, char *str)
{
	char	*part;
	char	*temp;

	part = NULL;
	if (self->save)
		part = *self->save;
	ft_memdel((void **)&self->addr);
	self->addr = gnl_split(str, '\n', 0);
	self->save = self->addr;
	if (part)
	{
		temp = *self->save;
		*self->save = ft_strjoin(part, temp);
		ft_strdel(&part);
		ft_strdel(&temp);
	}
}

int				gnl_readline(t_gnl *self, char **aline)
{
	char		buf[GNL_BUF + 1];
	ssize_t		ret;

	if (!self || read(self->fd, NULL, 0) < 0)
		return (-1);
	while (!gnl_pop(self, aline))
	{
		if (self->eof)
			return (0);
		if ((ret = read(self->fd, buf, GNL_BUF)) == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
			self->eof = 1;
		else
			gnl_push(self, buf);
	}
	return (1);
}
