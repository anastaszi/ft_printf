/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_floats2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:32:50 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 13:40:45 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*word(char sign, char letter, t_flag flag)
{
	if (letter == 'n')
		return ((ft_strchr("FGEA", flag.specifier)) ? "NAN" : "nan");
	else if ((letter == 'i') && (sign == '+'))
		return ((ft_strchr("FGEA", flag.specifier)) ? "INF" : "inf");
	else
		return ((ft_strchr("FGEA", flag.specifier)) ? "-INF" : "-inf");
}

int			before_after_dot(double num)
{
	if (num > 10)
		return (1 + before_after_dot(num / 10));
	else
		return (0);
}

int			check_double(double num, char **str, t_flag flag)
{
	char	*temp;
	char	*hex;
	int		check;

	*str = NULL;
	temp = double_to_bitschar(num);
	hex = str_to_hex(temp);
	check = 1;
	if (!ft_strcmp(hex, "7ff0000000000000"))
		*str = ft_stradd(str, word('+', 'i', flag));
	else if (!ft_strcmp(hex, "fff0000000000000"))
		*str = ft_stradd(str, word('-', 'i', flag));
	else if (!ft_strncmp(temp + 1, "11111111111", 11))
		*str = ft_stradd(str, word(0, 'n', flag));
	else if (num == 0.0 && temp[0] == '0')
		*str = ft_stradd(str, "0");
	else if (num == 0.0)
		*str = ft_stradd(str, "-0");
	else
		check = 0;
	ft_memdel((void **)&temp);
	ft_memdel((void **)&hex);
	return (check);
}

int			check_sign(double *num)
{
	if (*num < 0)
	{
		*num = -(*num);
		return (1);
	}
	return (0);
}

void		add_first(char **str, int i, t_flag flag)
{
	if (i)
		*str = ft_straddfirst(str, "-");
	else if (flag.flag_space)
		*str = ft_straddfirst(str, " ");
	else if (flag.flag_plus)
		*str = ft_straddfirst(str, "+");
	else
		;
}
