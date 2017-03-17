#include "libft.h"

char	*ft_straddchar(char **str, char add)
{
	char *new;

	new = ft_strnew(ft_strlen(*str) + 1);
	new = ft_strcpy(new, *str);
	new[ft_strlen(*str)] = add;
	ft_memdel((void**)str);
	return (new);
}