/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azimina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:57:42 by azimina           #+#    #+#             */
/*   Updated: 2016/12/05 17:06:22 by azimina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *b;

	b = dst;
	while ((*src) && (len != 0))
	{
		*b++ = *src++;
		len--;
	}
	while (len != 0)
	{
		*b++ = '\0';
		len--;
	}
	return (dst);
}
