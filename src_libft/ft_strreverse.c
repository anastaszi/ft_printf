#include "libft.h"

void ft_strreverse(char **str)
{
	char temp;
	int i;
	int len;
	len = ft_strlen(*str);
	i = 0;
	while (i < len/2)
	{
		temp = (*str)[len - 1 - i];
		(*str)[len - 1 - i] = (*str)[i];
		(*str)[i++] = temp;
	}
}