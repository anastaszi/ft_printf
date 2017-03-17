/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:46:19 by azimina           #+#    #+#             */
/*   Updated: 2016/12/02 14:36:04 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen(s);
	if (c == '\0')
		return (char *)s + i;
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)s + i;
		i--;
	}
	return (NULL);
}
