/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:30:48 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:30:51 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_to_bitschar(char *str_nt)
{
    char	*temp;
    char	*str;
    int		count;
    int		i;
    int		j;

    temp = str_nt;
    str = ft_strnewset(ft_strlen(str_nt) * 8, 0);
    count = 0;
    i = 0;
    while (i <= (int)(ft_strlen(str_nt) - 1))
    {
	j = 8;
	while (j-- > 0)
		str[count++] = ((temp[i] >> j) & 1) ? '1' : '0';
	i++;
    }
    return (str);
}

char	*double_to_bitschar(double num)
{
    char		*str;
    int			count;
    int			i;
    int			j;
    t_double_bits	a;

    str = ft_strnewset(sizeof(num) * 8, 0);
    count = 0;
    i = sizeof(num) - 1;
    a.f = num;
    while (i >= 0)
    {
        j = 8;
        while (j-- > 0)
            str[count++] = ((a.u[i] >> j) & 1) ? '1' : '0';
        i--;
    }
    return (str);
}

char *str_to_hex(char *str)
{
    int i;
    int count;
    char *hex;
    int sum;
    int len;

    len = ft_strlen(str)/4;
    hex = ft_strnewset(len, 0);
    count = 0;
    i = 0;
    while (i < len)
    {
        sum = 0;
        while (count/4 - i < 1)
        {
            sum = sum + ft_topower(2 * ((str[count] == '1') ? 1 : 0), 3 - count%4);
            count++;
        }
        hex[i] = LETTERSMIN[sum];
        i++; 
    }
    return (hex);
}
