/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:23:21 by azimina           #+#    #+#             */
/*   Updated: 2017/03/02 12:24:05 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_color(char *add, int i, int *j, int count)
{
	ft_putstr(add);
	*j = *j + count;
	return (i);
}

int	get_color(const char *str, int i, int *j)
{
	int count;

	if ((str[i + 1] == 'r') && (!ft_strncmp((str + i), "{red}", 5)))
		count = add_color("\x1b[31m", 4, j, ft_strlen("\x1b[31m"));
	else if ((str[i + 1] == 'g') && (!ft_strncmp((str + i), "{green}", 7)))
		count = add_color("\x1b[32m", 6, j, ft_strlen("\x1b[32m"));
	else if ((str[i + 1] == 'y') && (!ft_strncmp((str + i), "{yellow}", 8)))
		count = add_color("\x1b[33m", 7, j, ft_strlen("\x1b[33m"));
	else if ((str[i + 1] == 'b') && (!ft_strncmp((str + i), "{blue}", 6)))
		count = add_color("\x1b[34m", 5, j, ft_strlen("\x1b[34m"));
	else if ((str[i + 1] == 'm') && (!ft_strncmp((str + i), "{magenta}", 9)))
		count = add_color("\x1b[35m", 8, j, ft_strlen("\x1b[35m"));
	else if ((str[i + 1] == 'c') && (!ft_strncmp((str + i), "{cyan}", 6)))
		count = add_color("\x1b[36m", 5, j, ft_strlen("\x1b[36m"));
	else if ((str[i + 1] == 'e') && (!ft_strncmp((str + i), "{eoc}", 5)))
		count = add_color("\x1b[0m", 4, j, ft_strlen("\x1b[0m"));
	else
		count = add_color("{", 0, j, 1);
	return (count);
}
