/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:45:01 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:36:50 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_value(int *j, int *i)
{
	*i = *j;
}

void	arg_manip(t_flag rflag, va_list ap, int *j)
{
	char		*str;
	uintmax_t	temp;
	va_list		copy;
	int			num;

	str = NULL;
	if (rflag.posix == 1)
	{
		va_copy(copy, ap);
		num = rflag.posix_num;
		while (num-- > 1)
			temp = va_arg(copy, uintmax_t);
		str = getstr(rflag, copy);
		va_end(copy);
	}
	else
		str = getstr(rflag, ap);
	add_flag_params(str, j, rflag);
}

int		check_for_flag(const char *str)
{
	if ((str[0] == '%') && (str[1] != '\0'))
		return (1);
	else if ((str[0] == '%') && (str[1] == '\0'))
		return (2);
	else if (str[0] == '{')
		return (123);
	return (0);
}

void add_bad_width(t_flag rflag, int *j)
{
	char *temp;
	char c;

	c = (rflag.flag_zero) ? '0' : ' ';
	temp = (rflag.width) ? ft_strnewset(rflag.width, c) : NULL;
	if ((rflag.flag_minus == 1) && (temp != NULL))
		{
			ft_putchar(rflag.specifier);
			ft_putstr(temp + 1);
		}
	else if (temp != NULL)
		{
			ft_putstr(temp + 1);
			ft_putchar(rflag.specifier);
		}
	else
		ft_putchar(rflag.specifier);
	*j = *j + (!temp) +ft_strlen(temp);
	ft_memdel((void**)&temp);
}

void	add_flagged_params(int *j, int *i, va_list ap, const char *format)
{
	t_flag	rflag;
	int count;

	if ((count = check_for_flag(format + *i)) == 123)
		*i = *i + 1 + get_color(format, *i, j);
	else if (count == 1)
	{
		null_t_flag(&rflag);
		read_flag(&rflag, format, *i);
		check_valid_flag(rflag);
		put_flag_length(&rflag);
		correct_flag(&rflag, ap);
		if (rflag.specifier == 'n')
			put_value(j, va_arg(ap, int*));
		else if (ft_strchr("c", rflag.specifier) && rflag.length == NULL)
			add_chars(rflag, j, ap);
		else if (!ft_strchr(SPECIFS, rflag.specifier))
			add_bad_width(rflag, j);
		else
			arg_manip(rflag, ap, j);
		ft_memdel((void**)&rflag.length);
		*i = *i + 1 + rflag.index;
	}
	else
		*i = *i + 1;
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
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
