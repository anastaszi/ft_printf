/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:07:47 by azimina           #+#    #+#             */
/*   Updated: 2016/12/13 19:42:18 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	const unsigned char		*csrc;
	unsigned char			*cdst;
	size_t					i;

	csrc = (const unsigned char*)src;
	cdst = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (void *)dst + i + 1;
		i++;
	}
	return (NULL);
}
