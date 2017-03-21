/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:34:08 by azimina           #+#    #+#             */
/*   Updated: 2017/03/20 15:34:12 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	one_byte_char(char *str, int length, int add)
{
	int	sum;
	int	i;
	int	number;

	sum = 0;
	i = 0;
	while (i < length)
	{
		number = (str[i] == '1') ? 1 : 0;
		sum = sum + ft_topower(2 * number, length - 1 - i);
		i++;
	}
	return (sum + add);
}

static void	add_bytes(char *dest, char *str, int length)
{
	if (length < 8)
		dest[0] = (char)(one_byte_char(str, length, 0));
	else if (length > 7 && length < 12)
	{
		dest[0] = (char)(one_byte_char(str, length - 6, 192));
		dest[1] = (char)(one_byte_char(str + length - 6, 6, 128));
	}
	else if (length > 11 && length < 17)
	{
		dest[0] = (char)(one_byte_char(str, length - 12, 224));
		dest[1] = (char)(one_byte_char(str + length - 12, 6, 128));
		dest[2] = (char)(one_byte_char(str + length - 6, 6, 128));
	}
	else
	{
		dest[0] = (char)(one_byte_char(str, length - 18, 240));
		dest[1] = (char)(one_byte_char(str + length - 18, 6, 128));
		dest[2] = (char)(one_byte_char(str + length - 12, 6, 128));
		dest[3] = (char)(one_byte_char(str + length - 6, 6, 128));
	}
}

char		*wint_tocharray(wint_t ch)
{
	char	output[5];
	char	temp[32];
	int	count;
	int	i;

	ft_memset(output, 0, 5);
	ft_memset(temp, 0, 32);
	count = 0;
	i = 31;
	while (i-- >= 0)
		if ((ch >> i))
			temp[count++] = (ch >> i & 1) ? '1' : '0';
	add_bytes(output, temp, count);
	return (ft_strdup(output));
}

char		*wstrn_tocharray(wchar_t *str, int len)
{
	char	*chararray;
	char	*letter;
	int		i;

	chararray = NULL;
	letter = NULL;
	i = 0;
	while (*(str + i) && len > 0)
	{
		letter = wint_tocharray(*(str + i));
		if ((int)(len - ft_strlen(letter)) < 0)
			break;
		chararray = ft_stradd(&chararray, letter);
		len = len - ft_strlen(letter);
		ft_memdel((void **)&letter);
		i++;
	}
	return (chararray);
}

char		*wstr_tocharray(wchar_t *str)
{
	char	*chararray;
	char	*letter;
	int		i;

	chararray = NULL;
	letter = NULL;
	i = 0;
	while (*(str + i))
	{
		letter = wint_tocharray(*(str + i));
		chararray = ft_stradd(&chararray, letter);
		ft_memdel((void **)&letter);
		i++;
	}
	return (chararray);
}
