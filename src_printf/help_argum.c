/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:26:39 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:32:16 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void check_toread(char **str)
{
	char *temp;
	char ch;
	int i;
	temp = *str;
	i = 0;
	if (ft_strchr(temp, ' '))
		ch = ' ';
	else if (ft_strchr(temp, '+'))
		ch = '+';
	else if (ft_strchr(temp, '-'))
		ch = '-';
	else
		ch = 'n';
	if (temp[i] == '0' && ch != 'n')
	{
		temp[i++] = ch;
		while (temp[i] == '0')
			i++;
		temp[i] = '0';
	}
}

char	*check_precision_num(char *str, t_flag rflag)
{
	char	*temp;
	int		len;
	char	*nullstr;
	int i;

	temp = NULL;
	if (ft_strchr("dDiouxX", rflag.specifier) && !rflag.precision_num && !ft_strcmp(str, "0"))
		str[0] = '\0';
	if (rflag.flag_hash)
	{
		if (rflag.specifier == 'X' && ft_strlen(str))
			str = ft_straddfirst(&str, "0X");
		else if ((rflag.specifier == 'x' && ft_strlen(str)) || rflag.specifier == 'p')
			str = ft_straddfirst(&str, "0x");
		else if (ft_strchr("oO", rflag.specifier) && ft_strcmp(str, "0"))
			str = ft_straddfirst(&str, "0");
	}
	len = (int)ft_strlen(str);
	if (ft_strchr("sSaAgG", rflag.specifier) && rflag.precision && \
		rflag.precision_num < len && rflag.precision_num >= 0)
		temp = ft_strsub(str, 0, rflag.precision_num);
	else if (len)
		temp = ft_stradd(&temp, str);
	if (ft_strchr("dDioOuxX", rflag.specifier) && rflag.precision_num > len && rflag.precision)
	{
		i = (ft_strchr("dDi", rflag.specifier) && ft_strchr("- +", temp[0])) ? 1 : 0;
		nullstr = ft_strnewset((size_t)(rflag.precision_num + i - len), '0');
		temp = ft_straddfirst(&temp, nullstr);
		ft_memdel((void**)&nullstr);
	}
	ft_memdel((void**)&str);
	return (temp);
}

char	*check_width(char **str, t_flag rflag)
{
	char	*temp;
	int		len;
	int		dif;

	temp = NULL;
	len = (int)ft_strlen(*str);
	dif = rflag.width - len;
	if (dif > 0)
		temp = (rflag.flag_zero == 1 && len) ? ft_strnewset((size_t)dif, '0') \
	: ft_strnewset((size_t)dif, ' ');
	if (ft_strchr("fFdDi", rflag.specifier) && temp && rflag.flag_zero && !ft_isdigit((*str)[0]))
		{
			temp[0] = (*str)[0];
			(*str)[0] = '0';
		}
	return (temp);
}

void	add_flag_params_str(char *str, char **toread, t_flag rflag)
{
	char	*temp;
	char	*width_str;

	temp = check_precision_num(str, rflag);
	width_str = check_width(&temp, rflag);
	if (ft_strchr("dDi", rflag.specifier) && temp)
		check_toread(&temp);
	if ((rflag.flag_minus == 1) && (width_str != NULL))
	{
		*toread = ft_stradd(toread, temp);
		*toread = ft_stradd(toread, width_str);
	}
	else if (width_str != NULL)
	{
		*toread = ft_stradd(toread, width_str);
		*toread = ft_stradd(toread, temp);
	}
	else
		*toread = ft_stradd(toread, temp);
	ft_memdel((void**)&temp);
	ft_memdel((void**)&width_str);
}

void	arg_manip(t_flag rflag, va_list ap, char **toread)
{
	char		*str;
	uintmax_t	temp;
	va_list		copy;
	int			num;

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
	{
		if ((rflag.width_wc == 1) || (rflag.precision_wc == 1))
			add_wc(ap, &rflag);
		str = getstr(rflag, ap);
	}
	add_flag_params_str(str, toread, rflag);
}
