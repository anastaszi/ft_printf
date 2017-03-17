/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:57:03 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 16:09:04 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*map;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	map = (char *)malloc(len + 1);
	if (map != NULL)
	{
		while (i < (int)len)
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
