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

void	put_value(int *j, int *i)
{
	*i = *j;
}

int		check_for_flag(const char *str)
{
	if ((str[0] == '%') && (str[1] != '\0'))
		return (str[1] != '%' ? 1 : 37);
	else if ((str[0] == '%') && (str[1] == '\0'))
		exit(0);
	else if (str[0] == '{')
		return (123);
	else
		return (0);
}

void	add_flagged_params(int *j, int *i, va_list ap, const char *format)
{
	t_flag	rflag;

	if (check_for_flag(format + *i) != 1)
		add_char_or_color_to_str(j, format, i);
	else
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
		else
			arg_manip(rflag, ap, j);
		ft_memdel((void**)&rflag.length);
		*i = *i + 1 + rflag.index;
	}
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
