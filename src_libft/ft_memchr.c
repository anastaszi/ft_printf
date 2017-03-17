/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:31:53 by azimina           #+#    #+#             */
/*   Updated: 2016/12/02 14:31:56 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;

	p = s;
	while (n != 0)
	{
		if (*p == (unsigned char)c)
			return (void *)p;
		p++;
		n--;
	}
	return (NULL);
}
