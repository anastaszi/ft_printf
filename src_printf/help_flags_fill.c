/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flags_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:31:34 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:38:35 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_flag(t_flag *rflag, char c)
{
	if (c == ' ')
		rflag->flag_space = 1;
	else if (c == '+')
		rflag->flag_plus = 1;
	else if (c == '-')
		rflag->flag_minus = 1;
	else if (c == '0')
		rflag->flag_zero = 1;
	else if (c == '#')
		rflag->flag_hash = 1;
	else
		;
}

void	put_length(t_flag *rflag, const char *str, int *length, va_list ap)
{
	if ((*rflag).length != NULL)
	{
		rflag->bad = 1;
		va_end(ap);
	}
	else if ((str[*length] == 'h') && (str[1 + *length] == 'h'))
	{
		(*rflag).length = ft_strdup("hh");
		*length = *length + 1;
	}
	else if ((str[*length] == 'l') && (str[1 + *length] == 'l'))
	{
		(*rflag).length = ft_strdup("ll");
		*length = *length + 1;
	}
	else
		(*rflag).length = str_to_char((int)str[*length]);
}

void	add_wc(va_list ap, t_flag *rflag)
{
	int i;
	int m;

	i = va_arg(ap, int);
	m = 0;
	if (rflag->width_wc == 1)
	{
		if (i < 0)
		{
			rflag->flag_minus = 1;
			i = -1 * i;
		}
		if (rflag->width_elem == 1 || !rflag->width)
			rflag->width = i;
		m++;
	}
	if (rflag->precision_wc == 1)
		rflag->precision_num = (m) ? va_arg(ap, int) : i;
}

void	put_wc(t_flag *rflag, const char *str, int i, int *length)
{
	int temp;

	if (rflag->precision == 1)
		rflag->precision_wc = 1;
	else
	{
		if (rflag->width)
			rflag->width_elem = 1;
		rflag->width_wc = 1;
	}
	if (rflag->posix == 1)
	{
		temp = ft_atoi(str + i + 1 + *length);
		if (rflag->precision == 1)
			rflag->precision_wc_elem = temp;
		else
			rflag->width_elem = temp;
		*length = *length + rank(temp, 10) + 1;
		if (str[i + *length] != '$')
			exit(4);
	}
}

void	put_width(t_flag *rflag, const char *str, int i, int *length)
{
	int temp;

	temp = ft_atoi(str + i + *length);
	if (rflag->precision == 1)
		rflag->precision_num = temp;
	else
		rflag->width = temp;
	*length = *length + rank(temp, 10) - 1;
}
