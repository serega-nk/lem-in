/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 04:16:06 by bconchit          #+#    #+#             */
/*   Updated: 2019/11/15 08:12:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_index(char *str, char c)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
