#include "libft.h"

void ft_strdelpart(char **str, size_t start)
{
	char *temp;

	temp = *str;
	if (temp !=NULL && start < ft_strlen(temp))
	{
		while (temp[start] != '\0')
		{
			temp[start] = '\0';
			start++;
		}
	}
}