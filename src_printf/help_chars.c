/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:31:03 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:17:28 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		printchar(int *j, int i, t_flag rflag)
{
	char *width_str;

	if (rflag.width > 1)
		width_str = (rflag.flag_zero) ? \
					ft_strnewset((size_t)rflag.width - 1, '0') : \
					ft_strnewset((size_t)rflag.width - 1, ' ');
	else
		width_str = NULL;
	if ((rflag.flag_minus == 1) && (width_str != NULL))
	{
		ft_putchar(i);
		ft_putstr(width_str);
	}
	else if (width_str != NULL)
	{
		ft_putstr(width_str);
		ft_putchar(i);
	}
	else
		ft_putchar(i);
	*j = *j + 1 + ft_strlen(width_str);
	ft_memdel((void **)&width_str);
}

static void		wstring_manip(t_flag rflag, va_list ap, char **str)
{
	wchar_t		*ch;

	ch = va_arg(ap, wchar_t *);
	if (ch == NULL)
		*str = ft_stradd(str, "(null)");
	else if (rflag.precision && rflag.precision_num >= 0)
		*str = wstrn_tocharray(ch, rflag.precision_num);
	else
		*str = wstr_tocharray(ch);
}

void			string_manip(t_flag rflag, va_list ap, char **str)
{
	char		*s;

	if (rflag.length == NULL && rflag.specifier == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL && rflag.flag_zero)
			*str = ft_straddchar(str, '0');
		else if (s == NULL)
			*str = ft_stradd(str, "(null)");
		else if (rflag.precision && rflag.precision_num \
				< (int)ft_strlen(s) && rflag.precision_num >= 0)
			*str = ft_strnadd(str, s, rflag.precision_num);
		else
			*str = ft_stradd(str, s);
	}
	else
		wstring_manip(rflag, ap, str);
}

void			add_chars(t_flag rflag, int *j, va_list ap)
{
	int			i;
	uintmax_t	temp;
	va_list		copy;
	int			num;

	if (rflag.posix == 1)
	{
		va_copy(copy, ap);
		num = rflag.posix_num;
		while (num-- > 1)
			temp = va_arg(copy, uintmax_t);
		i = va_arg(copy, int);
		va_end(copy);
	}
	else
		i = va_arg(ap, int);
	printchar(j, i, rflag);
}

void			char_manip(va_list ap, char **str)
{
	wint_t i;

	i = va_arg(ap, wint_t);
	*str = wint_tocharray(i);
}
