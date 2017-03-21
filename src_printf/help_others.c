/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:33:46 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:33:48 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strprint_del(char **str)
{
	int count;

	count = ft_strlen(*str);
	ft_putstr(*str);
	ft_memdel((void**)str);
	return (count);
}

int	rank(unsigned long long value, int base)
{
	if (value < (unsigned long long)base)
		return (1);
	return (1 + rank((value / base), base));
}

char	*str_to_char(int ch)
{
	char *str;

	str = (char *)malloc(2);
	str[0] = (char)ch;
	str[1] = '\0';
	return (str);
}

void	good_number(long long int *temp, long long int max, long long int min)
{
	long long int i;

	while (*temp > max)
	{
		i = *temp - max - 1;
		*temp = min + i;
	}
	while (*temp < min)
	{
		i = min - *temp - 1;
		*temp = max - i;
	}
}
