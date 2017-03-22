/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:32:41 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:36:55 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_round(char **str, int *num)
{
	char	*temp;
	int		len;
	char	temporary;

	temp = *str;
	while (!ft_isdigit(*temp))
		temp++;
	if (temp[1] == '0')
	{
		len = ft_strlen(temp);
		if (len > 2)
		{
			temporary = temp[1];
			temp[1] = temp[2];
			temp[2] = temporary;
			temp[len - 1] = '\0';
		}
		else
			temp[len - 1] = '\0';
		*num = (*num >= 0) ? *num + 1 : *num - 1;
	}
}

static void	round_modification(char *src, char *dst, int *i, int len)
{
	int temporary;

	temporary = (src[len - 1] > '5' && src[len - 1] < '9') ? 2 : 1;
	while (*i < len)
	{
		if (ft_isdigit(src[len - 1 - *i]))
		{
			if (src[len - 1 - *i] != '9' && temporary)
			{
				dst[*i] = src[len - 1 - *i] + temporary;
				temporary--;
			}
			else if (src[len - 1 - *i] == '9' && temporary)
			{
				dst[*i] = '0';
				temporary = 1;
			}
			else
				dst[*i] = src[len - 1 - *i] + temporary;
		}
		else
			dst[*i] = src[len - 1 - *i];
		*i = *i + 1;
	}
}

static char	*round(char **str)
{
	int		length;
	char	*new;
	char	*temp;
	int		i;
	int		temporary;

	temp = *str;
	length = (int)ft_strlen(*str);
	i = 0;
	new = ft_strnewset(length, 0);
	if (temp[length - 1] == '9')
		new[i++] = '0';
	temporary = (temp[length - 1] > '5' && temp[length - 1] < '9') ? 2 : 1;
	round_modification(temp, new, &i, length);
	if (new[i - 1] == '0' && temporary)
		new = ft_straddchar(&new, '1');
	ft_strreverse(&new);
	ft_memdel((void**)str);
	return (new);
}

void		double_to_char(double num, t_flag flag, int power, char **str)
{
	double	weight;
	int		precision;

	precision = flag.precision_num + power + flag.flag_hash + 1;
	while (precision >= 0 || num > PRECISION || power >= 0)
	{
		weight = ft_topowerdouble(10.0, power);
		if (precision == 0 && (int)num == 0 && (int)(num) / weight < \
			(num) / weight && (int)(num / weight) > 0 && \
			(int)(num / weight) < 9)
			*str = ft_straddchar(str, '0' + (int)(num / weight) + 1);
		else
			*str = ft_straddchar(str, '0' + (int)(num / weight));
		num = num - (int)(num / weight) * weight;
		if (precision-- == 0 || (flag.precision_num == 0 && power == 0))
			break ;
		if (power-- == 0)
			*str = ft_straddchar(str, '.');
	}
	if ((*str)[ft_strlen(*str) - 1] > '5' || num / weight > 0.5)
		*str = round(str);
	if (ft_strchr(*str, '.'))
		(*str)[ft_strlen(*str) - 1] = '\0';
}

void		double_to_science(double num, t_flag flag, int power, char **str)
{
	int		temp;
	char	*e;

	if ((int)num)
		num = (num / ft_topowerdouble(10.0, power));
	while (!(int)num)
	{
		num = num * 10;
		power--;
	}
	temp = power;
	double_to_char(num, flag, 0, str);
	check_round(str, &temp);
	if (!flag.precision_num && flag.flag_hash)
		*str = ft_straddchar(str, '.');
	*str = ft_straddchar(str, flag.specifier);
	*str = (temp >= 0) ? ft_straddchar(str, '+') : ft_straddchar(str, '-');
	temp = ft_abc(temp);
	if (temp < 10)
		*str = ft_straddchar(str, '0');
	e = ft_itoa(temp);
	*str = ft_stradd(str, e);
	ft_memdel((void**)&e);
}
