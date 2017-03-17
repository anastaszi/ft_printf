/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posix_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:46:20 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:49:43 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sum_should_be(int i)
{
	int sum;

	sum = 0;
	while (i > 0)
	{
		sum = sum + i;
		i--;
	}
	return (sum);
}

void		check_posix(const char *str)
{
	int flags;
	int sum;
	int elem;
	int i;

	flags = 0;
	sum = 0;
	i = 0;
	while (*(str + i))
	{
		if (*str == '%')
		{
			elem = ft_atoi(str + i);
			sum = sum + elem;
			i = i + rank(elem, 10);
			if (*(str + i) != '$')
				if_so_exit(4);
			flags++;
		}
		i++;
	}
	if (sum != sum_should_be(flags))
		if_so_exit(4);
}

int			get_param_for_flag(va_list ap, int i)
{
	uintmax_t	current;
	va_list		copy;
	int			num;

	va_copy(copy, ap);
	while (i-- > 1)
		current = va_arg(copy, uintmax_t);
	num = va_arg(copy, int);
	va_end(copy);
	return (num);
}
