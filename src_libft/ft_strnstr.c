/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:36:46 by azimina           #+#    #+#             */
/*   Updated: 2016/12/08 20:26:57 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	m;
	char	*btemp;

	i = 0;
	m = 0;
	btemp = (char *)big;
	if (!*little)
		return ((char *)big);
	while ((btemp[i] != '\0') && (i < len))
	{
		if (btemp[i] != little[m])
		{
			i = i - m;
			m = 0;
		}
		else
			m++;
		i++;
		if (little[m] == '\0')
			return (&btemp[i - m]);
	}
	return (NULL);
}
