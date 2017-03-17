/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:51:30 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 13:08:15 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rank(int n)
{
	if (n < 10)
		return (1);
	return (1 + rank(n / 10));
}

static void	negative(long *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		length;
	int		neg;
	char	*number;
	long	num;

	neg = 0;
	num = (long)n;
	negative(&num, &neg);
	length = rank(num) + neg;
	if ((number = (char *)malloc(sizeof(char) * (length + 1))))
	{
		number[length] = '\0';
		while (length-- > 0)
		{
			number[length] = num % 10 + '0';
			num = num / 10;
		}
		if (neg == 1)
			number[0] = '-';
		return (number);
	}
	return (NULL);
}
