/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:54:56 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 19:41:31 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;
	char	*tdst;
	char	*tsrc;

	tdst = dst;
	tsrc = (char *)src;
	n = size;
	while (*tdst != '\0' && n-- != 0)
		tdst++;
	len = tdst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*tsrc != '\0')
	{
		if (n != 1)
		{
			*tdst++ = *tsrc;
			n--;
		}
		tsrc++;
	}
	*tdst = '\0';
	return (len + (tsrc - src));
}
