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
void add_hash(char **str, t_flag rflag)
{
	if (rflag.specifier == 'X' && ft_strlen(*str) && ft_strcmp(*str, "0"))
		*str = ft_straddfirst(str, "0X");
	else if ((rflag.specifier == 'x' && ft_strlen(*str) && ft_strcmp(*str, "0")) || rflag.specifier == 'p')
			*str = ft_straddfirst(str, "0x");
	else if (ft_strchr("oO", rflag.specifier) && (*str)[0] != '0')
		*str = ft_straddfirst(str, "0");
}

static void add_precision_double(char **str, t_flag rflag)
{
	char *nullstr;

	if (!ft_strcmp(*str, "0") && rflag.precision_num)
	{
		nullstr = ft_strnewset((size_t)(rflag.precision_num), '0');
		*str = ft_straddchar(str, '.');
		*str = ft_stradd(str, nullstr);
		if (ft_strchr("eE", rflag.specifier))
			*str = ft_stradd(str, "E+00");
		ft_memdel((void**)&nullstr);
	}
}

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
	else if (rflag.specifier == 'x')
		return (itoa_long_base(temp, 16, rflag, LETTERSMIN));
	else if (rflag.specifier == 'o' || rflag.specifier == 'O')
		return (itoa_long_base(temp, 8, rflag, LETTERSMIN));
	else if (ft_strchr("diuUD", rflag.specifier))
		return (itoa_long_base(temp, 10, rflag, LETTERSMIN));
	else if (rflag.specifier == 'p' && (temp || !rflag.precision || rflag.precision_num))
		return (itoa_long_base(temp, 16, rflag, LETTERSMIN));
	else
		return (NULL);
}

static void	string_manip(t_flag rflag, va_list ap, char **str)
{
	char *s;
	wchar_t *ch;
	
	if (rflag.length == NULL && rflag.specifier == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL && rflag.flag_zero)
			*str = ft_straddchar(str, '0');
		else if (s == NULL)
			*str = ft_stradd(str, "(null)");
		else if (rflag.precision && rflag.precision_num < (int)ft_strlen(s) && rflag.precision_num >= 0)
			*str = ft_strnadd(str, s, rflag.precision_num);
		else
			*str = ft_stradd(str, s);
	}
	else
	{
		ch = va_arg(ap, wchar_t *);
		if (ch == NULL)
			*str = ft_stradd(str, "(null)");
		else if (rflag.precision && rflag.precision_num >= 0)
			*str = wstrn_tocharray(ch, rflag.precision_num);
		else
			*str = wstr_tocharray(ch);
	}
}

static void	char_manip(va_list ap, char **str)
{
	wint_t i;
	
	i = va_arg(ap, wint_t);
		//if (i < 256)
	*str = wint_tocharray(i);
		//else
			//	if_so_exit('c');

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

char *add_numb_precision(char **str, t_flag rflag)
{
	char *new;
	char *nullstr;
	char *temp;
	int i;
	char ch;

	new = NULL;
	ch = (*str)[0];
	i = (ft_isdigit(ch)) ? 0 : 1;
	temp = (i) ? (*str + 1) : *str;
	new = ft_strnewset((size_t)(rflag.precision_num + i), '\0');
	if (i)
		new = ft_straddchar(&new, ch);
	i = rflag.precision_num + i - (int)ft_strlen(*str);
	nullstr = (i) ? ft_strnewset((size_t)(i), '0') : NULL;
	new = (nullstr) ? ft_stradd(&new, nullstr) : NULL;
	new = ft_stradd(&new, temp);
	ft_memdel((void**)&nullstr);
	ft_memdel((void**)str);
	return(new);
}

void check_precision_num(char **str, t_flag rflag)
{
	int		len;

	if ((rflag.specifier != 'p' && !rflag.precision_num && (!ft_strcmp(*str, "0") || (!ft_isdigit((*str)[0]) && !ft_strcmp(*str + 1, "0")))))
			(*str)[0] = '\0';
	len = (int)ft_strlen(*str);
	if (rflag.precision_num >= len && ft_strlen(*str) && rflag.precision)
			*str = add_numb_precision(str, rflag);
	if (rflag.flag_hash)
		add_hash(str, rflag);
}

char		*getstr(t_flag rflag, va_list ap)
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