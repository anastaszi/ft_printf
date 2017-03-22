/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:32:29 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:22:38 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*getstr(t_flag rflag, va_list ap)
{
	char *str;

	str = NULL;
	if ((ft_strchr("sS", rflag.specifier)))
		string_manip(rflag, ap, &str);
	else if ((ft_strchr("cC", rflag.specifier)))
		char_manip(ap, &str);
	else if ((ft_strchr("diouxXOUDp", rflag.specifier)))
	{
		str = int_manip(ap, rflag);
		check_precision_num(&str, rflag);
	}
	else if ((ft_strchr("fFeE", rflag.specifier)))
	{
		double_manip(rflag, ap, &str);
		add_precision_double(&str, rflag);
	}
	else if (rflag.specifier == '%')
		str = ft_stradd(&str, "%");
	return (str);
}

static void		print_out(char *str, int *j, t_flag rflag)
{
	char	*width_str;

	width_str = check_width(&str, rflag);
	if (width_str != NULL && (rflag.flag_minus == 1 || (rflag.specifier == 'p' \
					&& rflag.flag_zero && !ft_strcmp(str, "0x0"))))
		*j = *j + strprint_del(&str) + strprint_del(&width_str);
	else if (width_str != NULL)
		*j = *j + strprint_del(&width_str) + strprint_del(&str);
	else if (ft_strlen(str))
		*j = *j + strprint_del(&str);
	else if (ft_strchr("cC", rflag.specifier))
		{
			ft_memdel((void**)&str);
			*j = *j + 1;
		}
	else
		strprint_del(&str);
}

static void		arg_manip(t_flag rflag, va_list ap, int *j)
{
	char		*str;
	uintmax_t	temp;
	va_list		copy;
	int			num;

	str = NULL;
	if (rflag.posix == 1 && rflag.posix_num)
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
	print_out(str, j, rflag);
}

void			add_flagged_params(int *j, int *i, va_list ap, \
		const char *format)
{
	t_flag	rflag;

	if (format[*i] == '{')
		*i = *i + 1 + get_color(format, *i, j);
	else if (format[*i] == '%' && format[*i + 1] != '\0')
	{
		null_t_flag(&rflag);
		if (read_flag(&rflag, format, i, ap))
		{
			put_flag_length(&rflag);
			correct_flag(&rflag, ap);
			if (rflag.specifier == 'n')
				put_n_value(j, ap, rflag);
			else if (ft_strchr("c", rflag.specifier) && rflag.length == NULL)
				add_chars(rflag, j, ap);
			else if (!ft_strchr(SPECIFS, rflag.specifier))
				add_bad_width(rflag, j);
			else
				arg_manip(rflag, ap, j);
		}
		ft_memdel((void**)&rflag.length);
	}
	else
		*i = *i + 1;
}
