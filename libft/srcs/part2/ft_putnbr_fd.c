/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 00:30:18 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/07 01:07:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nn;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		nn = (unsigned int)(-n);
	else
		nn = (unsigned int)n;
	if (nn / 10 > 0)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd('0' + nn % 10, fd);
}
