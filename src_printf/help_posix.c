/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_posix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:33:55 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:33:56 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
