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

void add_hash(char **str, t_flag rflag)
{
	if (rflag.specifier == 'X' && ft_strlen(*str))
		*str = ft_straddfirst(str, "0X");
	else if ((rflag.specifier == 'x' && ft_strlen(*str)) || rflag.specifier == 'p')
		*str = ft_straddfirst(str, "0x");
	else if (ft_strchr("oO", rflag.specifier) && ft_strcmp(*str, "0"))
		*str = ft_straddfirst(str, "0");
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
	nullstr = ft_strnewset((size_t)(rflag.precision_num + i - (int)ft_strlen(*str)), '0');
	new = ft_stradd(&new, nullstr);
	new = ft_stradd(&new, temp);
	ft_memdel((void**)&nullstr);
	ft_memdel((void**)str);
	return(new);
}
char	*check_precision_num(char *str, t_flag rflag)
{
	char	*temp;
	int		len;
	
	temp = NULL;
	if (ft_strchr("dDioOuxX", rflag.specifier) && !rflag.precision_num && (!ft_strcmp(str, "0") || (!ft_isdigit(str[0]) && !ft_strcmp(str + 1, "0"))))
		ft_strdelpart(&str, 0);
	if (rflag.flag_hash)
		add_hash(&str, rflag);
	if ((len = (int)ft_strlen(str)))
		temp = ft_stradd(&temp, str);
	if (ft_strchr("dDioOuxX", rflag.specifier) && rflag.precision_num >= len && temp && rflag.precision)
		temp = add_numb_precision(&temp, rflag);
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
	if (ft_strchr("fFdDi", rflag.specifier) && temp && \
		rflag.flag_zero && !ft_isdigit((*str)[0]))
		{
			temp[0] = (*str)[0];
			(*str)[0] = '0';
		}
	return (temp);
}

void printchar(int *j, int i, t_flag rflag)
{
	char *width_str;
 
	width_str = (rflag.width > 1) ? ft_strnewset((size_t)rflag.width - 1, ' ') : NULL;
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

void add_chars(t_flag rflag, int *j, va_list ap)
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
	{
		if ((rflag.width_wc == 1) || (rflag.precision_wc == 1))
			add_wc(ap, &rflag);
		i = va_arg(ap, int);
	}
	printchar(j, i, rflag);
}

void	add_flag_params(char *str, int *j, t_flag rflag)
{
	char	*temp;
	char	*width_str;

	temp = check_precision_num(str, rflag);
	width_str = check_width(&temp, rflag);
	if (ft_strchr("dDi", rflag.specifier) && temp)
		check_toread(&temp);
	if ((rflag.flag_minus == 1) && (width_str != NULL))
		*j = *j + strprint_del(&temp) + strprint_del(&width_str);
	else if (width_str != NULL)
		*j = *j + strprint_del(&width_str) + strprint_del(&temp);
	else if (temp != NULL)
		*j = *j + strprint_del(&temp);
	else
		ft_putstr("(null)");
}