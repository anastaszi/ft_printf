/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:30:25 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:30:34 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int		i;
	int		j;

	va_start(ap, format);
	i = 0;
	j = 0;
	while (*(format + i) != '\0')
	{
		while (!check_for_flag(format + i) && (format[i] != '\0'))
		{
			ft_putchar(format[i++]);
			j++;
		}
		if (format[i] != '\0')
			add_flagged_params(&j, &i, ap, format);
	}
	va_end(ap);
	return (j);
}
