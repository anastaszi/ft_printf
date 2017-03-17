/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:37:18 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:40:32 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_sign_type(t_flag flag, int a[2])
{
	if (ft_strchr("diD", flag.specifier))
		a[0] = 1;
	else
		a[0] = 0;
	if (flag.tchar)
		a[1] = 0;
	else if (flag.tint)
		a[1] = 1;
	else if (flag.tshort)
		a[1] = 2;
	else if (flag.tlong)
		a[1] = 3;
	else
		a[1] = 4;
}

int		negative_long(unsigned long long *n, t_flag flag,\
		long long value)
{
	int sign_type[2];

	get_sign_type(flag, sign_type);
	if ((sign_type[0] == 1) && (value < 0))
		*n = value * (-1);
	else if (sign_type[1] == 0)
		*n = (unsigned char)value;
	else if (sign_type[1] == 1)
		*n = (unsigned int)value;
	else if (sign_type[1] == 2)
		*n = (unsigned short)value;
	else if (sign_type[1] == 3)
		*n = (unsigned long)value;
	else
		*n = (unsigned long long)value;
	if (sign_type[0] == 1 && value < 0)
		return (1);
	else if (flag.flag_plus || flag.flag_space)
		return (1);
	else
		return (0);
}

char	*itoa_long_base(long long value, int base, t_flag flag, char *str)
{
	unsigned long long	num;
	int					neg;
	int					length;
	char				*res;

	neg = negative_long(&num, flag, value);
	length = rank(num, base) + neg;
	if ((res = (char *)malloc(sizeof(char) * (length + 1))))
	{
		res[length] = '\0';
		while (length-- > 0)
		{
			res[length] = str[num % base];
			num = num / base;
		}
		if (neg == 1)
		{
			if (value < 0 && ft_strchr("diD", flag.specifier))
				res[0] = '-';
			else
				res[0] = (flag.flag_plus) ? '+' : ' ';
		}
		return (res);
	}
	return (NULL);
}
