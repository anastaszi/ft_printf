/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 23:14:48 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 13:06:20 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (l < 0)
		{
			ft_putchar_fd('-', fd);
			l = -l;
		}
		if (l / 10)
			ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(l % 10 + '0', fd);
	}
}
