/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_floats3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:32:58 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:33:02 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void add_precision_double(char **str, t_flag rflag)
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

void	double_manip(t_flag rflag, va_list ap, char **str)
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
