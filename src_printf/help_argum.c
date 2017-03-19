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
void printchar(int *j, int i, t_flag rflag)
{
	char *width_str;

	if (rflag.width > 1)
		width_str = (rflag.flag_zero) ? ft_strnewset((size_t)rflag.width - 1, '0') : ft_strnewset((size_t)rflag.width - 1, ' ');
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

char	*check_width(char **str, t_flag rflag)
{
	char	*temp;
	int		len;
	int		dif;

	temp = NULL;
	len = (int)ft_strlen(*str);
	dif = (rflag.specifier == 'S' && !len &&rflag.precision_num> 0)? 0: (rflag.width - len);
	if (dif > 0 && rflag.flag_zero == 1 && (len || (!len && rflag.specifier == 'S')))
		temp = ft_strnewset((size_t)dif, '0');
	else if (dif > 0)
		temp = ft_strnewset((size_t)dif, ' ');
	if (ft_strchr("fFdDi", rflag.specifier) && temp && \
		rflag.flag_zero && !ft_isdigit((*str)[0]))
		{
			temp[0] = (*str)[0];
			(*str)[0] = '0';
		}
	return (temp);
}

void	add_flag_params(char *str, int *j, t_flag rflag)
{
	char	*width_str;

	width_str = check_width(&str, rflag);
	if (ft_strchr("dDi", rflag.specifier) && str)
		check_toread(&str);
	if (width_str != NULL && (rflag.flag_minus == 1 || (rflag.specifier == 'p' && rflag.flag_zero && !ft_strcmp(str, "0x0"))))
		*j = *j + strprint_del(&str) + strprint_del(&width_str);
	else if (width_str != NULL)
		*j = *j + strprint_del(&width_str) + strprint_del(&str);
	else if (ft_strlen(str))
		*j = *j + strprint_del(&str);
	else if (ft_strchr("cC", rflag.specifier))
		*j = *j + 1;
	else 
		ft_putstr("");
}