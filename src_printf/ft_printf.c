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

void	put_value(char **str, int *i)
{
	*i = ft_strlen(*str);
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

void	add_flagged_params(char **str, int *i, va_list ap, const char *format)
{
	t_flag	rflag;

	if (check_for_flag(format + *i) != 1)
		add_char_or_color_to_str(str, format, i);
	else
	{
		null_t_flag(&rflag);
		read_flag(&rflag, format, *i);
		check_valid_flag(rflag);
		put_flag_length(&rflag);
		correct_flag(&rflag, ap);
		if (rflag.specifier == 'n')
			put_value(str, va_arg(ap, int*));
		else
			arg_manip(rflag, ap, str);
		ft_memdel((void**)&rflag.length);
		*i = *i + 1 + rflag.index;
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	char	*str;

	va_start(ap, format);
	i = 0;
	str = NULL;
	while (*(format + i) != '\0')
	{
		j = i;
		while (!check_for_flag(format + i) && (format[i] != '\0'))
			write(1, format[i++], 1);
		if (format[i] != '\0')
			add_flagged_params(&str, &i, ap, format);
	}
	va_end(ap);
	return (strprint_del(&str));
}
