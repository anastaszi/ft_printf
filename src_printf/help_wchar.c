/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:34:08 by azimina           #+#    #+#             */
/*   Updated: 2017/03/21 12:24:35 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	b_char(char *str, int length, int add)
{
	int		sum;
	int		i;
	int		number;

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

static void	add_bytes(char **dest, char *str, int len)
{
	if (len < 8)
		*dest = ft_straddchar(dest, (char)(b_char(str, len, 0)));
	else if (len > 7 && len < 12)
	{
		*dest = ft_straddchar(dest, (char)(b_char(str, len - 6, 192)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 6, 6, 128)));
	}
	else if (len > 11 && len < 17)
	{
		*dest = ft_straddchar(dest, (char)(b_char(str, len - 12, 224)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 12, 6, 128)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 6, 6, 128)));
	}
	else
	{
		*dest = ft_straddchar(dest, (char)(b_char(str, len - 18, 240)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 18, 6, 128)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 12, 6, 128)));
		*dest = ft_straddchar(dest, (char)(b_char(str + len - 6, 6, 128)));
	}
}

char		*wint_tocharray(wint_t ch)
{
	char	*output;
	char	temp[32];
	int		count;
	int		i;

	output = NULL;
	ft_memset(temp, '\0', 32);
	count = 0;
	i = 31;
	while (i-- >= 0)
		if ((ch >> i))
			temp[count++] = (ch >> i & 1) ? '1' : '0';
	add_bytes(&output, temp, count);
	return (output);
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
			{
				ft_memdel((void **)&letter);
				break ;
			}
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
