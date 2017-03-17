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

static int	add_color(char **str, char *add, int i)
{
	*str = ft_stradd(str, add);
	return (i);
}

static int	get_color(const char *str, int i, char **toput)
{
	int count;

	if ((str[i + 1] == 'r') && (!ft_strncmp((str + i), "{red}", 5)))
		count = add_color(toput, "\x1b[31m", 4);
	else if ((str[i + 1] == 'g') && (!ft_strncmp((str + i), "{green}", 7)))
		count = add_color(toput, "\x1b[32m", 6);
	else if ((str[i + 1] == 'y') && (!ft_strncmp((str + i), "{yellow}", 8)))
		count = add_color(toput, "\x1b[33m", 7);
	else if ((str[i + 1] == 'b') && (!ft_strncmp((str + i), "{blue}", 6)))
		count = add_color(toput, "\x1b[34m", 5);
	else if ((str[i + 1] == 'm') && (!ft_strncmp((str + i), "{magenta}", 9)))
		count = add_color(toput, "\x1b[35m", 8);
	else if ((str[i + 1] == 'c') && (!ft_strncmp((str + i), "{cyan}", 6)))
		count = add_color(toput, "\x1b[36m", 5);
	else if ((str[i + 1] == 'e') && (!ft_strncmp((str + i), "{eoc}", 5)))
		count = add_color(toput, "\x1b[0m", 4);
	else
		count = add_color(toput, "{", 0);
	return (count);
}

void		add_char_or_color_to_str(char **toput, const char *str, int *index)
{
	if (str[*index] == '%')
	{
		*toput = ft_stradd(toput, "%");
		*index = *index + 2;
	}
	else
		*index = *index + 1 + get_color(str, *index, toput);
}
