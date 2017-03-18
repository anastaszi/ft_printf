#include "libft.h"

void ft_strdelpart(char **str, size_t start)
{
	if (*str!=NULL && start < ft_strlen(*str))
	{
		while (str[start] != '\0')
		{
			str[start] = '\0';
			start++;
		}
	}
}