/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:33:36 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:33:38 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void check_int(long long int *temp, t_flag rflag)
{
	if (rflag.tchar)
		good_number(temp, CHAR_MAX, CHAR_MIN);
	if (rflag.tshort)
		good_number(temp, SHRT_MAX, SHRT_MIN);
	if (rflag.tint)
		good_number(temp, INT_MAX, INT_MIN);
}

static void add_hash(char **str, t_flag rflag)
{
	if (rflag.specifier == 'X' && ft_strlen(*str) && ft_strcmp(*str, "0"))
		*str = ft_straddfirst(str, "0X");
	else if ((rflag.specifier == 'x' && ft_strlen(*str) && ft_strcmp(*str, "0")) || rflag.specifier == 'p')
			*str = ft_straddfirst(str, "0x");
	else if (ft_strchr("oO", rflag.specifier) && (*str)[0] != '0')
		*str = ft_straddfirst(str, "0");
}

static char *add_numb_precision(char **str, t_flag rflag)
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

char	*int_manip(va_list ap, t_flag rflag)
{
	long long temp;

	if ((rflag.tint || rflag.tshort || rflag.tchar) && !rflag.bad)
		temp = va_arg(ap, int);
	else if (((rflag.tlong == 1) && !rflag.tsizet) || rflag.bad)
		temp = va_arg(ap, long int);
	else if (rflag.tlonglong == 1)
		temp = va_arg(ap, long long int);
	else if (rflag.tsizet == 1)
		temp = va_arg(ap, size_t);
	else
		temp = va_arg(ap, intmax_t);
	if (!rflag.bad)
		check_int(&temp, rflag);
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
