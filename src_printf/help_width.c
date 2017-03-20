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

static void check_toread(char **str)
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

static void small_reverse(char **str, char **temp)
{
	if (ft_strlen(*temp) == 1)
	{
		(*str)[0] = 'x';
		(*str)[1] = '0';
	}
	else
	{
		(*temp)[1] = 'x';
		(*str)[1] = '0';
	}
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
	if (rflag.flag_hash && temp && temp[0] == '0')
		small_reverse(str, &temp);
	if (ft_strchr("dDi", rflag.specifier) && str)
		check_toread(str);
	return (temp);
}

void add_bad_width(t_flag rflag, int *j)
{
	char *temp;
	char c;

	c = (rflag.flag_zero) ? '0' : ' ';
	temp = (rflag.width) ? ft_strnewset(rflag.width, c) : NULL;
	if ((rflag.flag_minus == 1) && (temp != NULL))
		{
			ft_putchar(rflag.specifier);
			ft_putstr(temp + 1);
		}
	else if (temp != NULL)
		{
			ft_putstr(temp + 1);
			ft_putchar(rflag.specifier);
		}
	else
		ft_putchar(rflag.specifier);
	*j = *j + (!temp) +ft_strlen(temp);
	ft_memdel((void**)&temp);
}