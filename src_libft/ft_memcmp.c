/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:11:12 by azimina           #+#    #+#             */
/*   Updated: 2016/12/05 17:11:15 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *ts1;
	unsigned char *ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	if ((s1 == NULL) && (s2 == NULL))
		return (0);
	while (len--)
	{
		if (*ts1 != *ts2)
			return (*ts1 - *ts2);
		else
		{
			ts1++;
			ts2++;
		}
	}
	return (0);
}
