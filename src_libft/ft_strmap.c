/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:56:14 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 16:08:32 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			map[i] = f(s[i]);
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
