/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:45:29 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:45:49 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*int_manip(va_list ap, t_flag rflag)
{
	long long temp;

	if ((rflag.tint == 1) || (rflag.tshort == 1) || (rflag.tchar == 1))
		temp = va_arg(ap, int);
	else if ((rflag.tlong == 1) && (rflag.tsizet == 0))
		temp = va_arg(ap, long int);
	else if (rflag.tlonglong == 1)
		temp = va_arg(ap, long long int);
	else if (rflag.tsizet == 1)
		temp = va_arg(ap, size_t);
	else
		temp = va_arg(ap, intmax_t);
	if (rflag.specifier == 'X')
		return (itoa_long_base(temp, 16, rflag, LETTERSMAX));
	else if ((rflag.specifier == 'x') || (rflag.specifier == 'p'))
		return (itoa_long_base(temp, 16, rflag, LETTERSMIN));
	else if (rflag.specifier == 'o' || rflag.specifier == 'O')
		return (itoa_long_base(temp, 8, rflag, LETTERSMIN));
	else
		return (itoa_long_base(temp, 10, rflag, LETTERSMIN));
}

static void	string_manip(t_flag rflag, va_list ap, char **str)
{
	if (ft_strchr("Cc", rflag.specifier))
		*str = wint_tocharray(va_arg(ap, wint_t));
	else if (rflag.length == NULL && rflag.specifier == 's')
		*str = ft_stradd(str, va_arg(ap, char *));
	else
		*str = wstr_tocharray(va_arg(ap, wchar_t *));
}
static void	double_manip(t_flag rflag, va_list ap, char **str)
{
	double num;
	int power;
	int i;

	num = va_arg(ap, double);
	i = 0;
	if (!check_double(num, str, rflag))
	{	
		i = check_sign(&num);
		power = before_after_dot(num);
		if ((ft_strchr("fF", rflag.specifier)))
		{
			double_to_char(num, rflag, power, str);
			if (!rflag.precision_num && rflag.flag_hash)
				*str = ft_straddchar(str, '.');
		}
		else
			double_to_science(num, rflag, power, str);
		add_first(str, i, rflag);
	}
}

char		*getstr(t_flag rflag, va_list ap)
{
	char *str;

	str = NULL;
	if ((ft_strchr("sSCc", rflag.specifier)))
		string_manip(rflag, ap, &str);
	else if ((ft_strchr("diouxXOUDp", rflag.specifier)))
		str = int_manip(ap, rflag);
	else if ((ft_strchr("fFeE", rflag.specifier)))
		double_manip(rflag, ap, &str);
	return (str);
}
